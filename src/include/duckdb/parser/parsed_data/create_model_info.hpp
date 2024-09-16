//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/parser/parsed_data/create_model_info.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/parser/parsed_data/create_info.hpp"
#include "duckdb/common/limits.hpp"

namespace duckdb {

struct CreateModelInfo : public CreateInfo {
	CreateModelInfo();

	//! Model name to create
	string name;
	//! The type of the model
	uint8_t model_type;
	//! The path of the stored model
	string model_path;
	//! Output set names
    vector<string> out_names;
    //! Output set types
    vector<LogicalType> out_types;

public:
	unique_ptr<CreateInfo> Copy() const override;

public:
	DUCKDB_API void Serialize(Serializer &serializer) const override;
	DUCKDB_API static unique_ptr<CreateInfo> Deserialize(Deserializer &deserializer);

	string ToString() const override;
};

} // namespace duckdb
