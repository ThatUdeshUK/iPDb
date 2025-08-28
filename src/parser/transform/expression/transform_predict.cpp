#include "duckdb/common/enum_util.hpp"
#include "duckdb/common/string_util.hpp"
#include "duckdb/parser/expression/predict_expression.hpp"
#include "duckdb/parser/transformer.hpp"

#include <regex>

namespace duckdb {

static duckdb_libpgquery::PGColumnRef *MakePGColumnRef(const std::string &col_name) {
    // Allocate the node
    auto *colref = (duckdb_libpgquery::PGColumnRef *) duckdb_libpgquery::newNode(sizeof(duckdb_libpgquery::PGColumnRef), duckdb_libpgquery::T_PGColumnRef);

    // The field name(s) are stored as a list of `PGValue` nodes
    auto *pgval = duckdb_libpgquery::makeString(col_name.c_str());

    colref->fields = duckdb_libpgquery::lcons(pgval, (duckdb_libpgquery::PGList *) NULL);  // one-element list for column name
    colref->location = -1;               // usually -1 if no SQL text position

    return colref;
}

unique_ptr<ParsedExpression> Transformer::TransformPredict(duckdb_libpgquery::PGPredictExpr &root) {
	auto result = make_uniq<PredictExpression>();

	auto qname = TransformQualifiedName(*root.model_name);
	result->model_name = qname.name;

	if (root.prompt != nullptr)
		result->prompt = root.prompt;

	static const std::regex out_re(R"((\w+)\s+(INTEGER|VARCHAR))", std::regex_constants::icase);
	auto words_begin = std::sregex_iterator(result->prompt.begin(), result->prompt.end(), out_re);
	auto words_end = std::sregex_iterator();

	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		result->out_col_name = match[1];
		
		std::string type = match[2].str();
		LogicalTypeId id;
		if (type == "VARCHAR") {
			id = LogicalTypeId::VARCHAR;
		} else if (type == "INTEGER") {
			id = LogicalTypeId::INTEGER;
		} else {
			throw InternalException("Unsupported column type");
		}
		result->out_col_type = LogicalType(id);
	}

	static const std::regex in_re(R"(\{\{\w+\}\})");
	words_begin = std::sregex_iterator(result->prompt.begin(), result->prompt.end(), in_re);
	words_end = std::sregex_iterator();

	for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
		std::smatch match = *i;
		std::string match_str = match.str();
		auto attr = match_str.substr(2, match_str.size() - 4);		
		
		result->input_col_names.push_back(attr);

		auto *cr = MakePGColumnRef(attr.c_str());

		auto target = PGPointerCast<duckdb_libpgquery::PGNode>(cr);
		auto expr = TransformExpression(*target);
		result->children.push_back(std::move(expr));			
	}

	SetQueryLocation(*result, root.location);
	return std::move(result);
}

} // namespace duckdb
