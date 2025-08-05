#include "duckdb/parser/expression/predict_expression.hpp"

#include <utility>
#include "duckdb/common/string_util.hpp"
#include "duckdb/common/exception.hpp"
#include "duckdb/common/types/hash.hpp"

#include "duckdb/common/serializer/serializer.hpp"
#include "duckdb/common/serializer/deserializer.hpp"

namespace duckdb {

PredictExpression::PredictExpression() : ParsedExpression(ExpressionType::PREDICT, ExpressionClass::PREDICT) {
}

string PredictExpression::ToString() const {
	return "PredictExpression";
}

bool PredictExpression::Equal(const PredictExpression &a, const PredictExpression &b) {
	if (a.model_name != b.model_name || a.prompt != b.prompt) {
		return false;
	}
	return true;
}

hash_t PredictExpression::Hash() const {
	hash_t result = ParsedExpression::Hash();
	result = CombineHash(result, duckdb::Hash<const char *>(model_name.c_str()));
	result = CombineHash(result, duckdb::Hash<const char *>(prompt.c_str()));
	return result;
}

unique_ptr<ParsedExpression> PredictExpression::Copy() const {
	unique_ptr<TableRef> source_copy;
	if (source) {
		source_copy = source->Copy();
	}
	auto copy = make_uniq<PredictExpression>();
	copy->CopyProperties(*this);
	return std::move(copy);
}

void PredictExpression::Verify() const {
	D_ASSERT(!model_name.empty());
}

} // namespace duckdb
