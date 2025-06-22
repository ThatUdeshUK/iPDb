//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/parser/tableref/predictref.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/parser/tableref.hpp"
#include "duckdb/parser/query_node/select_node.hpp"

namespace duckdb {

//! Represents a PREDICT expression
class PredictRef : public TableRef {
public:
	static constexpr const TableReferenceType TYPE = TableReferenceType::PREDICT;

public:
	explicit PredictRef() : TableRef(TableReferenceType::PREDICT) {
	}

	//! The source table of the predict
	unique_ptr<TableRef> source;
	//! The (optional) source table of the predict
	unique_ptr<TableRef> opt_source;
	//! The model name for the predict
	string model_name;
	//! The prompt for llm tasks
	string prompt;
	//! Aliases for the column names
	vector<string> column_name_alias;

public:
	string ToString() const override;
	bool Equals(const TableRef &other_p) const override;

	unique_ptr<TableRef> Copy() override;

	//! Deserializes a blob back into a PredictRef
	void Serialize(Serializer &serializer) const override;
	static unique_ptr<TableRef> Deserialize(Deserializer &source);
};
} // namespace duckdb
