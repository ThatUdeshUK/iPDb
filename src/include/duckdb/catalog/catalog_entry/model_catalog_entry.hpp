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
	uint8_t model_type;
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
