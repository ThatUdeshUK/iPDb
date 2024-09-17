#include "duckdb/catalog/catalog_entry/model_catalog_entry.hpp"

#include "duckdb/catalog/catalog.hpp"
#include "duckdb/catalog/catalog_entry/schema_catalog_entry.hpp"
#include "duckdb/common/enum_util.hpp"
#include "duckdb/common/exception.hpp"
#include "duckdb/parser/parsed_data/create_model_info.hpp"
#include "duckdb/catalog/dependency_manager.hpp"
#include "duckdb/common/operator/add.hpp"
#include "duckdb/transaction/duck_transaction.hpp"

#include <algorithm>
#include <sstream>

namespace duckdb {

ModelData::ModelData(CreateModelInfo &info)
    : model_path(info.model_path), model_type(info.model_type), rel_name(info.rel_name),
	input_set_names(info.input_set_names), exclude_set_names(info.exclude_set_names), opt_rel_name(info.opt_rel_name),
	opt_set_names(info.opt_set_names), exclude_opt_set_names(info.exclude_opt_set_names), out_names(info.out_names), 
	out_types(info.out_types), options(info.options) {
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

// void ModelCatalogEntry::SetData(string v_path, uint8_t v_type) {
// 	data.model_path = v_path;
// 	data.model_type = v_type;
// }

unique_ptr<CreateInfo> ModelCatalogEntry::GetInfo() const {
	auto model_data = GetData();

	auto result = make_uniq<CreateModelInfo>();
	result->catalog = catalog.GetName();
	result->schema = schema.name;
	result->name = name;
	result->model_path = model_data.model_path;
	result->model_type = model_data.model_type;
	result->rel_name = model_data.rel_name;
	result->input_set_names = model_data.input_set_names;
	result->exclude_set_names = model_data.exclude_set_names;
	result->opt_rel_name = model_data.opt_rel_name;
	result->opt_set_names = model_data.opt_set_names;
	result->exclude_opt_set_names = model_data.exclude_opt_set_names;
	result->out_names = model_data.out_names;
	result->out_types = model_data.out_types;
	result->options = model_data.options;
	result->dependencies = dependencies;
	result->comment = comment;
	result->tags = tags;
	return std::move(result);
}

string ModelCatalogEntry::ToSQL() const {
	auto model_data = GetData();

	std::stringstream ss;
	ss << "CREATE " << EnumUtil::ToChars<ModelType>(model_data.model_type);
	ss << " MODEL " << name;
	ss << " PATH '" << model_data.model_path;
	//TODO: add attach on expresion
	ss << "' OUTPUT(...); ";
	return ss.str();
}
} // namespace duckdb
