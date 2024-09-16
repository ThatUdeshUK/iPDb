#include "duckdb/parser/statement/create_statement.hpp"
#include "duckdb/parser/parsed_data/create_model_info.hpp"
#include "duckdb/parser/transformer.hpp"
#include "duckdb/common/enum_class_hash.hpp"
#include "duckdb/common/unordered_set.hpp"
#include "duckdb/common/operator/cast_operators.hpp"

namespace duckdb {

unique_ptr<CreateStatement> Transformer::TransformCreateModel(duckdb_libpgquery::PGCreateModelStmt &stmt) {
	auto result = make_uniq<CreateStatement>();
	auto info = make_uniq<CreateModelInfo>();

	auto qname = TransformQualifiedName(*stmt.model);
	info->catalog = qname.catalog;
	info->schema = qname.schema;
	info->name = qname.name;
	
	info->model_type = stmt.model_type;
	info->model_path = stmt.model_path;

	info->temporary = !stmt.model->relpersistence;
	info->on_conflict = TransformOnConflict(stmt.onconflict);

	result->info = std::move(info);
	return result;
}

} // namespace duckdb
