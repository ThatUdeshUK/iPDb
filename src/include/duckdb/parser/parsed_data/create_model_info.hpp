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

enum class ModelInfo : uint8_t {
	// Model start
	MODEL_NAME,
	// Mdole type
	MODEL_TYPE,
	// Model path
	MODEL_PATH
};

struct CreateModelInfo : public CreateInfo {
	CreateModelInfo();

	//! Model name to create
	string name;
	//! The type of the model
	uint8_t model_type;
	//! The path of the stored model
	string model_path;

public:
	unique_ptr<CreateInfo> Copy() const override;

public:
	DUCKDB_API void Serialize(Serializer &serializer) const override;
	DUCKDB_API static unique_ptr<CreateInfo> Deserialize(Deserializer &deserializer);

	string ToString() const override;
};

} // namespace duckdb
