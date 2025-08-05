//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/parser/expression/function_expression.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/parser/parsed_expression.hpp"
#include "duckdb/parser/tableref.hpp"

namespace duckdb {
//! Represents a function call
class PredictExpression : public ParsedExpression {
public:
	static constexpr const ExpressionClass TYPE = ExpressionClass::PREDICT;

public:
	DUCKDB_API PredictExpression();

	//! The source table of the predict
	unique_ptr<TableRef> source;
	//! The model name for the predict
	string model_name;
	//! The prompt for llm tasks
	string prompt;

public:
	string ToString() const override;

	unique_ptr<ParsedExpression> Copy() const override;

	static bool Equal(const PredictExpression &a, const PredictExpression &b);
	hash_t Hash() const override;

	void Serialize(Serializer &serializer) const override;
	static unique_ptr<ParsedExpression> Deserialize(Deserializer &deserializer);

	void Verify() const override;
};
} // namespace duckdb
