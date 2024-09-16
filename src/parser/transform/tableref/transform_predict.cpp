#include "duckdb/parser/tableref/predictref.hpp"
#include "duckdb/parser/transformer.hpp"

namespace duckdb {

unique_ptr<TableRef> Transformer::TransformPredict(duckdb_libpgquery::PGPredictExpr &root) {
	auto result = make_uniq<PredictRef>();

	auto qname = TransformQualifiedName(*root.model_name);
	result->model_name = qname.name;

	result->source = TransformTableRefNode(*root.source);
    if (root.has_opt) {
	    result->opt_source = TransformTableRefNode(*root.opt_source);
    }
	result->alias = TransformAlias(root.alias, result->column_name_alias);

	SetQueryLocation(*result, root.location);
	return std::move(result);
}

} // namespace duckdb
