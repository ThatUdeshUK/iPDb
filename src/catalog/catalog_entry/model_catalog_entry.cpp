#include "duckdb/catalog/catalog_entry/model_catalog_entry.hpp"

#include "duckdb/catalog/catalog.hpp"
#include "duckdb/catalog/catalog_entry/schema_catalog_entry.hpp"
#include "duckdb/common/exception.hpp"
#include "duckdb/parser/parsed_data/create_model_info.hpp"
#include "duckdb/catalog/dependency_manager.hpp"
#include "duckdb/common/operator/add.hpp"
#include "duckdb/transaction/duck_transaction.hpp"

#include <algorithm>
#include <sstream>

namespace duckdb {

ModelData::ModelData(CreateModelInfo &info)
    : model_path(info.model_path), model_type(info.model_type) {
}

ModelCatalogEntry::ModelCatalogEntry(Catalog &catalog, SchemaCatalogEntry &schema, CreateModelInfo &info)
    : StandardEntry(CatalogType::MODEL_ENTRY, schema, catalog, info.name), data(info) {
	this->temporary = info.temporary;
	this->comment = info.comment;
	this->tags = info.tags;
}

unique_ptr<CatalogEntry> ModelCatalogEntry::Copy(ClientContext &context) const {
	auto info_copy = GetInfo();
	auto &cast_info = info_copy->Cast<CreateModelInfo>();

	auto result = make_uniq<ModelCatalogEntry>(catalog, schema, cast_info);
	result->data = GetData();

	return std::move(result);
}

ModelData ModelCatalogEntry::GetData() const {
	lock_guard<mutex> model_lock(lock);
	return data;
}

void ModelCatalogEntry::SetData(string v_path, uint8_t v_type) {
	data.model_path = v_path;
	data.model_type = v_type;
}

unique_ptr<CreateInfo> ModelCatalogEntry::GetInfo() const {
	auto model_data = GetData();

	auto result = make_uniq<CreateModelInfo>();
	result->catalog = catalog.GetName();
	result->schema = schema.name;
	result->name = name;
	result->model_path = model_data.model_path;
	result->model_type = model_data.model_type;
	result->dependencies = dependencies;
	result->comment = comment;
	result->tags = tags;
	return std::move(result);
}

string ModelCatalogEntry::ToSQL() const {
	auto model_data = GetData();

	std::stringstream ss;
	ss << "CREATE MODEL ";
	ss << name;
	ss << " ( " << model_data.model_type;
	ss << " , " << model_data.model_path;
	ss << " ); ";
	return ss.str();
}
} // namespace duckdb
