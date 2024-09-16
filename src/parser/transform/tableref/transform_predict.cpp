#include "duckdb/parser/tableref/predictref.hpp"
#include "duckdb/parser/transformer.hpp"

namespace duckdb {

unique_ptr<TableRef> Transformer::TransformPredict(duckdb_libpgquery::PGPredictExpr &root) {
	auto result = make_uniq<PredictRef>();

	auto qname = TransformQualifiedName(*root.model_name);
	result->model_name = qname.name;

	result->source = TransformTableRefNode(*root.source);
    if (root.has_opt) {
	    result->opt_source = TransformTableRefNode(*root.opt_source);
    }
	result->alias = TransformAlias(root.alias, result->column_name_alias);

    auto feat_col_node = PGPointerCast<duckdb_libpgquery::PGPredictFeatExpr>(root.input_feat);
    
    if (feat_col_node && feat_col_node->input_set) {
        for (auto c = feat_col_node->input_set->head; c != nullptr; c = lnext(c)) {
            result->input_set_names.push_back(reinterpret_cast<duckdb_libpgquery::PGValue *>(c->data.ptr_value)->val.str);
        }
    }

    if (feat_col_node && feat_col_node->exclude_set) {
        for (auto c = feat_col_node->exclude_set->head; c != nullptr; c = lnext(c)) {
            result->exclude_set_names.push_back(reinterpret_cast<duckdb_libpgquery::PGValue *>(c->data.ptr_value)->val.str);
        }
    }

    auto opt_col_node = PGPointerCast<duckdb_libpgquery::PGPredictFeatExpr>(root.opt_feat);
    
    if (opt_col_node  && opt_col_node->input_set) {
        for (auto c = opt_col_node->input_set->head; c != nullptr; c = lnext(c)) {
            result->opt_set_names.push_back(reinterpret_cast<duckdb_libpgquery::PGValue *>(c->data.ptr_value)->val.str);
        }
    }

    if (opt_col_node  && opt_col_node->exclude_set) {
        for (auto c = opt_col_node->exclude_set->head; c != nullptr; c = lnext(c)) {
            result->exclude_opt_set_names.push_back(reinterpret_cast<duckdb_libpgquery::PGValue *>(c->data.ptr_value)->val.str);
        }
    }

	SetQueryLocation(*result, root.location);
	return std::move(result);
}

} // namespace duckdb
