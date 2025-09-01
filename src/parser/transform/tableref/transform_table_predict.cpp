#include "duckdb/parser/tableref/table_predict_ref.hpp"
#include "duckdb/parser/transformer.hpp"

namespace duckdb {

unique_ptr<TableRef> Transformer::TransformTablePredict(duckdb_libpgquery::PGPredictExpr &root) {
	auto result = make_uniq<TablePredictRef>();

	auto qname = TransformQualifiedName(*root.model_name);
	result->model_name = qname.name;

	if (root.prompt != nullptr)
		result->prompt = root.prompt;

	if (root.source) {
		result->source = TransformTableRefNode(*root.source);
	}
	
	if (root.has_opt) {
		result->opt_source = TransformTableRefNode(*root.opt_source);
	}
	result->alias = TransformAlias(root.alias, result->column_name_alias);

	SetQueryLocation(*result, root.location);
	return std::move(result);
}

} // namespace duckdb
