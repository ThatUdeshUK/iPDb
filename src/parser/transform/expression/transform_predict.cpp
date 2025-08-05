#include "duckdb/common/enum_util.hpp"
#include "duckdb/common/string_util.hpp"
#include "duckdb/parser/expression/predict_expression.hpp"
#include "duckdb/parser/transformer.hpp"

namespace duckdb {

unique_ptr<ParsedExpression> Transformer::TransformPredict(duckdb_libpgquery::PGPredictExpr &root) {
	auto result = make_uniq<PredictExpression>();

	auto qname = TransformQualifiedName(*root.model_name);
	result->model_name = qname.name;

	if (root.prompt != nullptr)
		result->prompt = root.prompt;

	result->source = TransformTableRefNode(*root.source);

	SetQueryLocation(*result, root.location);
	return std::move(result);
}

} // namespace duckdb
