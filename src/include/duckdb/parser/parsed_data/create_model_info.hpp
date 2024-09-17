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
#include "duckdb/common/enums/model_type.hpp"
#include "duckdb/common/case_insensitive_map.hpp"

namespace duckdb {

struct CreateModelInfo : public CreateInfo {
	CreateModelInfo();

	//! Model name to create
	string name;
	//! The type of the model
	ModelType model_type;
	//! The path of the stored model
	string model_path;

	//! The relation attached to
	string rel_name;
	//! Input set names
	vector<string> input_set_names;
	//! Exclude set names
	vector<string> exclude_set_names;

	//! The relation attached to
	string opt_rel_name;
	//! Input set names
	vector<string> opt_set_names;
	//! Exclude set names
	vector<string> exclude_opt_set_names;

	//! Output set names
	vector<string> out_names;
	//! Output set types
	vector<LogicalType> out_types;

	case_insensitive_map_t<Value> options;

public:
	unique_ptr<CreateInfo> Copy() const override;

public:
	DUCKDB_API void Serialize(Serializer &serializer) const override;
	DUCKDB_API static unique_ptr<CreateInfo> Deserialize(Deserializer &deserializer);

	string ToString() const override;
};

} // namespace duckdb
