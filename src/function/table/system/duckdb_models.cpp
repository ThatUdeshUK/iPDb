#include "duckdb/function/table/system_functions.hpp"

#include "duckdb/catalog/catalog.hpp"
#include "duckdb/catalog/catalog_entry/schema_catalog_entry.hpp"
#include "duckdb/catalog/catalog_entry/model_catalog_entry.hpp"
#include "duckdb/common/exception.hpp"
#include "duckdb/common/numeric_utils.hpp"
#include "duckdb/main/client_context.hpp"
#include "duckdb/main/client_data.hpp"

namespace duckdb {

struct DuckDBModelsData : public GlobalTableFunctionState {
	DuckDBModelsData() : offset(0) {
	}

	vector<reference<ModelCatalogEntry>> entries;
	idx_t offset;
};

static unique_ptr<FunctionData> DuckDBModelsBind(ClientContext &context, TableFunctionBindInput &input,
                                                 vector<LogicalType> &return_types, vector<string> &names) {
	names.emplace_back("database_name");
	return_types.emplace_back(LogicalType::VARCHAR);

	names.emplace_back("database_oid");
	return_types.emplace_back(LogicalType::BIGINT);

	names.emplace_back("schema_name");
	return_types.emplace_back(LogicalType::VARCHAR);

	names.emplace_back("schema_oid");
	return_types.emplace_back(LogicalType::BIGINT);

	names.emplace_back("model_name");
	return_types.emplace_back(LogicalType::VARCHAR);

	names.emplace_back("model_oid");
	return_types.emplace_back(LogicalType::BIGINT);

	names.emplace_back("comment");
	return_types.emplace_back(LogicalType::VARCHAR);

	names.emplace_back("tags");
	return_types.emplace_back(LogicalType::MAP(LogicalType::VARCHAR, LogicalType::VARCHAR));

	names.emplace_back("temporary");
	return_types.emplace_back(LogicalType::BOOLEAN);

	names.emplace_back("model_type");
	return_types.emplace_back(LogicalType::UTINYINT);

	names.emplace_back("model_path");
	return_types.emplace_back(LogicalType::VARCHAR);

	names.emplace_back("rel_name");
	return_types.emplace_back(LogicalType::VARCHAR);

	names.emplace_back("input_set_count");
	return_types.emplace_back(LogicalType::BIGINT);

	names.emplace_back("exclude_set_count");
	return_types.emplace_back(LogicalType::BIGINT);

	names.emplace_back("opt_rel_name");
	return_types.emplace_back(LogicalType::VARCHAR);

	names.emplace_back("opt_set_count");
	return_types.emplace_back(LogicalType::BIGINT);

	names.emplace_back("exclude_opt_set_count");
	return_types.emplace_back(LogicalType::BIGINT);

	names.emplace_back("output_count");
	return_types.emplace_back(LogicalType::BIGINT);

	names.emplace_back("options");
	return_types.emplace_back(LogicalType::MAP(LogicalType::VARCHAR, LogicalType::VARCHAR));

	names.emplace_back("sql");
	return_types.emplace_back(LogicalType::VARCHAR);

	return nullptr;
}

unique_ptr<GlobalTableFunctionState> DuckDBModelsInit(ClientContext &context, TableFunctionInitInput &input) {
	auto result = make_uniq<DuckDBModelsData>();

	// scan all the schemas for tables and collect themand collect them
	auto schemas = Catalog::GetAllSchemas(context);
	for (auto &schema : schemas) {
		schema.get().Scan(context, CatalogType::MODEL_ENTRY,
		                  [&](CatalogEntry &entry) { result->entries.push_back(entry.Cast<ModelCatalogEntry>()); });
	};
	return std::move(result);
}

void DuckDBModelsFunction(ClientContext &context, TableFunctionInput &data_p, DataChunk &output) {
	auto &data = data_p.global_state->Cast<DuckDBModelsData>();
	if (data.offset >= data.entries.size()) {
		// finished returning values
		return;
	}
	// start returning values
	// either fill up the chunk or return all the remaining columns
	idx_t count = 0;
	while (data.offset < data.entries.size() && count < STANDARD_VECTOR_SIZE) {
		auto &model = data.entries[data.offset++].get();
		auto model_data = model.GetData();

		// return values:
		idx_t col = 0;
		// database_name, VARCHAR
		output.SetValue(col++, count, model.catalog.GetName());
		// database_oid, BIGINT
		output.SetValue(col++, count, Value::BIGINT(NumericCast<int64_t>(model.catalog.GetOid())));
		// schema_name, VARCHAR
		output.SetValue(col++, count, Value(model.schema.name));
		// schema_oid, BIGINT
		output.SetValue(col++, count, Value::BIGINT(NumericCast<int64_t>(model.schema.oid)));
		// model_name, VARCHAR
		output.SetValue(col++, count, Value(model.name));
		// model_oid, BIGINT
		output.SetValue(col++, count, Value::BIGINT(NumericCast<int64_t>(model.oid)));
		// comment, VARCHAR
		output.SetValue(col++, count, Value(model.comment));
		// tags, MAP(VARCHAR, VARCHAR)
		output.SetValue(col++, count, Value::MAP(model.tags));
		// temporary, BOOLEAN
		output.SetValue(col++, count, Value::BOOLEAN(model.temporary));
		// model_type, UTINYINT
		output.SetValue(col++, count, Value::UTINYINT(model_data.model_type));
		// model_path, VARCHAR
		output.SetValue(col++, count, Value(model_data.model_path));
		// rel_name, VARCHAR
		output.SetValue(col++, count, Value(model_data.rel_name));
		// input_set_count, LogicalType::BIGINT
		output.SetValue(col++, count, Value::BIGINT(NumericCast<int64_t>(model_data.input_set_names.size())));
		// exclude_set_count, LogicalType::BIGINT
		output.SetValue(col++, count, Value::BIGINT(NumericCast<int64_t>(model_data.exclude_set_names.size())));
		// opt_rel_name, VARCHAR
		output.SetValue(col++, count, Value(model_data.opt_rel_name));
		// opt_set_count, LogicalType::BIGINT
		output.SetValue(col++, count, Value::BIGINT(NumericCast<int64_t>(model_data.opt_set_names.size())));
		// exclude_opt_set_count, LogicalType::BIGINT
		output.SetValue(col++, count, Value::BIGINT(NumericCast<int64_t>(model_data.exclude_opt_set_names.size())));
		// output_count, LogicalType::BIGINT
		output.SetValue(col++, count, Value::BIGINT(NumericCast<int64_t>(model_data.out_types.size())));
		// options MAP(VARCHAR, VARCHAR)
		unordered_map<string, string> option_out;
		for (const auto &element : model_data.options) {
			stringstream ss;
			ss << element.second;
			option_out.insert({element.first, ss.str()});
		}
		output.SetValue(col++, count, Value::MAP(option_out));
		// sql, LogicalType::VARCHAR
		output.SetValue(col++, count, Value(model.ToSQL()));

		count++;
	}
	output.SetCardinality(count);
}

void DuckDBModelsFun::RegisterFunction(BuiltinFunctions &set) {
	set.AddFunction(
	    TableFunction("duckdb_models", {}, DuckDBModelsFunction, DuckDBModelsBind, DuckDBModelsInit));
}

} // namespace duckdb
