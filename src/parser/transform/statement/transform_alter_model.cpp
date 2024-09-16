#include "duckdb/common/enum_class_hash.hpp"
#include "duckdb/common/unordered_set.hpp"
#include "duckdb/parser/parsed_data/alter_table_info.hpp"
#include "duckdb/parser/parsed_data/create_sequence_info.hpp"
#include "duckdb/parser/statement/alter_statement.hpp"
#include "duckdb/parser/transformer.hpp"

namespace duckdb {

unique_ptr<AlterStatement> Transformer::TransformAlterModel(duckdb_libpgquery::PGAlterModelStmt &stmt) {
	auto result = make_uniq<AlterStatement>();

	auto qname = TransformQualifiedName(*stmt.model);
	auto sequence_catalog = qname.catalog;
	auto sequence_schema = qname.schema;
	auto sequence_name = qname.name;

	result->info->if_not_found = TransformOnEntryNotFound(stmt.missing_ok);
	return result;
}
} // namespace duckdb
