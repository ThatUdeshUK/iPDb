#include "duckdb/parser/parsed_data/create_model_info.hpp"
#include "duckdb/catalog/catalog_entry/schema_catalog_entry.hpp"
#include "duckdb/catalog/catalog_entry/table_catalog_entry.hpp"
#include "duckdb/catalog/catalog.hpp"

namespace duckdb {

CreateModelInfo::CreateModelInfo()
    : CreateInfo(CatalogType::MODEL_ENTRY, INVALID_SCHEMA), name(string()), model_type(0), model_path(string()) {
}

unique_ptr<CreateInfo> CreateModelInfo::Copy() const {
	auto result = make_uniq<CreateModelInfo>();
	CopyProperties(*result);
	result->name = name;
	result->schema = schema;
	result->model_type = model_type;
	result->model_path = model_path;
	return std::move(result);
}

string CreateModelInfo::ToString() const {
	std::stringstream ss;
	ss << "CREATE";
	if (on_conflict == OnCreateConflict::REPLACE_ON_CONFLICT) {
		ss << " OR REPLACE";
	}
	if (temporary) {
		ss << " TEMPORARY";
	}
	ss << " MODEL ";
	if (on_conflict == OnCreateConflict::IGNORE_ON_CONFLICT) {
		ss << " IF NOT EXISTS ";
	}
	ss << QualifierToString(temporary ? "" : catalog, schema, name);
	ss << " ( ";
	ss << model_type << " ";
	ss << model_path << " ";
	ss << " );";
	return ss.str();
}

} // namespace duckdb
