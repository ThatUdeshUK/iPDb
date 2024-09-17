//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/catalog/catalog_entry/sequence_catalog_entry.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/catalog/standard_entry.hpp"
#include "duckdb/common/mutex.hpp"
#include "duckdb/common/enums/model_type.hpp"
#include "duckdb/parser/parsed_data/create_model_info.hpp"
#include "duckdb/parser/parsed_data/alter_table_info.hpp"

namespace duckdb {
class DuckTransaction;
class ModelCatalogEntry;

struct ModelData {
	explicit ModelData(CreateModelInfo &info);

	//! The model path
	string model_path;
	//! The model type
	ModelType model_type;
	//! The attached relation
	string rel_name;
	//! Input set names
    vector<string> input_set_names;
	//! Exclude set names
    vector<string> exclude_set_names;
	//! The optional attached relation
	string opt_rel_name;
	//! Optional input set names
    vector<string> opt_set_names;
	//! Optional exclude set names
    vector<string> exclude_opt_set_names;
	//! Output set names
    vector<string> out_names;
    //! Output set types
    vector<LogicalType> out_types;
	//! Options
	case_insensitive_map_t<Value> options;
};

//! A model catalog entry
class ModelCatalogEntry : public StandardEntry {
public:
	static constexpr const CatalogType Type = CatalogType::MODEL_ENTRY;
	static constexpr const char *Name = "model";

public:
	//! Create a real TableCatalogEntry and initialize storage for it
	ModelCatalogEntry(Catalog &catalog, SchemaCatalogEntry &schema, CreateModelInfo &info);

public:
	unique_ptr<CatalogEntry> Copy(ClientContext &context) const override;
	unique_ptr<CreateInfo> GetInfo() const override;

	ModelData GetData() const;
	void SetData(string v_path, uint8_t type);

	string ToSQL() const override;

private:
	//! Lock for getting a value on the sequence
	mutable mutex lock;
	//! Model data
	ModelData data;
};
} // namespace duckdb
