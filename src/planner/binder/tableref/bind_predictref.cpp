#include "duckdb/parser/tableref/predictref.hpp"
#include "duckdb/planner/binder.hpp"
#include "duckdb/planner/tableref/bound_predictref.hpp"
#include "duckdb/parser/tableref/subqueryref.hpp"
#include "duckdb/parser/query_node/select_node.hpp"
#include "duckdb/catalog/catalog.hpp"
#include "duckdb/catalog/catalog_entry/model_catalog_entry.hpp"

namespace duckdb {

struct BindModelData {
	vector<reference<ModelCatalogEntry>> entries;
};

unique_ptr<BoundTableRef> Binder::BindBoundPredict(PredictRef &ref) {
	auto result = make_uniq<BoundPredictRef>();
	result->bound_predict.model_name = std::move(ref.model_name);

	auto models = make_uniq<BindModelData>();
	auto schemas = Catalog::GetAllSchemas(context);
	for (auto &schema : schemas) {
		schema.get().Scan(context, CatalogType::MODEL_ENTRY, [&](CatalogEntry &entry) {
			auto &item = entry.Cast<ModelCatalogEntry>();
			if (item.name == result->bound_predict.model_name) {
				models->entries.push_back(item);
			}
		});
	};

	if (models->entries.empty()) {
		throw InternalException("Catalog Error: Model with name `" + result->bound_predict.model_name +
		                        "` does not exist!");
	}

	auto &stored_model = models->entries[0].get();
	auto stored_model_data = stored_model.GetData();
	result->bound_predict.model_type = stored_model_data.model_type;
	result->bound_predict.model_path = stored_model_data.model_path;
	result->bound_predict.options = stored_model_data.options;

	result->bind_index = GenerateTableIndex();
	result->child_binder = Binder::CreateBinder(context, this);
	result->children.push_back(result->child_binder->Bind(*ref.source));

	vector<string> names;
	vector<LogicalType> input_types;
	result->child_binder->bind_context.GetTypesAndNames(names, input_types);
	vector<LogicalType> types(input_types);

	vector<idx_t> input_mask;
	if (!stored_model_data.input_set_names.empty()) {
		for (const std::string &input_col : stored_model_data.input_set_names) {
			bool feature_found = false;
			for (auto it = names.begin(); it != names.end(); ++it) {
				auto index = static_cast<idx_t>(std::distance(names.begin(), it));
				if (input_col == *it) {
					input_mask.push_back(index);
					feature_found = true;
					break;
				}
			}
			if (!feature_found) {
				throw BinderException("Input tabel should contain the BY feature columns");
			}
		}
	} else if (!stored_model_data.exclude_set_names.empty()) {
		for (auto it = names.begin(); it != names.end(); ++it) {
			bool exclude_found = false;
			for (const std::string &exclude_col : stored_model_data.exclude_set_names) {
				if (exclude_col == *it) {
					exclude_found = true;
					break;
				}
			}
			if (exclude_found) {
				continue;
			}
			auto index = static_cast<idx_t>(std::distance(names.begin(), it));
			input_mask.push_back(index);
		}
	} else {
		for (size_t i = 0; i < names.size(); i++) {
			input_mask.push_back(i);
		}
	}
	result->bound_predict.input_mask = std::move(input_mask);

	if (result->bound_predict.model_type == ModelType::GNN) {
		vector<string> opt_names;
		vector<LogicalType> opt_types;
		result->opt_binder = Binder::CreateBinder(context, this);
		result->children.push_back(result->opt_binder->Bind(*ref.opt_source));

		result->opt_binder->bind_context.GetTypesAndNames(opt_names, opt_types);

		vector<idx_t> opt_mask;
		if (!stored_model_data.opt_set_names.empty()) {
			for (const std::string &input_col : stored_model_data.opt_set_names) {
				bool feature_found = false;
				for (auto it = opt_names.begin(); it != opt_names.end(); ++it) {
					auto index = static_cast<idx_t>(std::distance(opt_names.begin(), it));
					if (input_col == *it) {
						opt_mask.push_back(index);
						feature_found = true;
						break;
					}
				}
				if (!feature_found) {
					throw BinderException("Input tabel should contain the BY feature columns");
				}
			}
		} else if (!stored_model_data.exclude_opt_set_names.empty()) {
			for (auto it = opt_names.begin(); it != opt_names.end(); ++it) {
				bool exclude_found = false;
				for (const std::string &exclude_col : stored_model_data.exclude_opt_set_names) {
					if (exclude_col == *it) {
						exclude_found = true;
						break;
					}
				}
				if (exclude_found) {
					continue;
				}
				auto index = static_cast<idx_t>(std::distance(opt_names.begin(), it));
				opt_mask.push_back(index);
			}
		} else {
			for (size_t i = 0; i < opt_names.size(); i++) {
				opt_mask.push_back(i);
			}
		}
		result->bound_predict.opt_mask = std::move(opt_mask);
	}

	vector<string> result_names = stored_model_data.out_names;
	names.insert(names.end(), std::make_move_iterator(result_names.begin()),
	             std::make_move_iterator(result_names.end()));

	vector<LogicalType> result_types = stored_model_data.out_types;
	types.insert(types.end(), std::make_move_iterator(result_types.begin()),
	             std::make_move_iterator(result_types.end()));

	result->bound_predict.types = types;
	result->bound_predict.input_set_types = std::move(input_types);
	result->bound_predict.result_set_names = std::move(stored_model_data.out_names);
	result->bound_predict.result_set_types = std::move(stored_model_data.out_types);

	auto subquery_alias = ref.alias.empty() ? "__unnamed_predict" : ref.alias;
	bind_context.AddGenericBinding(result->bind_index, subquery_alias, names, types);
	MoveCorrelatedExpressions(*result->child_binder);
	return std::move(result);
}

unique_ptr<BoundTableRef> Binder::Bind(PredictRef &ref) {
	if (!ref.source) {
		throw InternalException("Predict without a source!?");
	}

	// Wrap the source in a projection
	auto subquery = make_uniq<SelectNode>();
	subquery->select_list.push_back(make_uniq<StarExpression>());
	subquery->from_table = std::move(ref.source);

	auto subquery_select = make_uniq<SelectStatement>();
	subquery_select->node = std::move(subquery);
	auto subquery_ref = make_uniq<SubqueryRef>(std::move(subquery_select));

	ref.source = std::move(subquery_ref);

	return BindBoundPredict(ref);
}

} // namespace duckdb
