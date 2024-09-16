#include "duckdb/parser/tableref/predictref.hpp"
#include "duckdb/parser/transformer.hpp"

namespace duckdb {

unique_ptr<TableRef> Transformer::TransformPredict(duckdb_libpgquery::PGPredictExpr &root) {
	auto result = make_uniq<PredictRef>();
    result->model_type = root.model_type;
    result->model_name = root.model_name;

	result->source = TransformTableRefNode(*root.source);
    if (result->model_type == 2) {
	    result->opt_source = TransformTableRefNode(*root.opt_source);
    }
	result->alias = TransformAlias(root.alias, result->column_name_alias);

    auto feat_col_node = PGPointerCast<duckdb_libpgquery::PGPredictFeatExpr>(root.input_feat);
    
    if (feat_col_node && feat_col_node->input_set) {
        for (auto c = feat_col_node->input_set->head; c != nullptr; c = lnext(c)) {
            result->input_set_names.push_back(reinterpret_cast<duckdb_libpgquery::PGValue *>(c->data.ptr_value)->val.str);
        }
    }

    if (feat_col_node && feat_col_node->exclude_set) {
        for (auto c = feat_col_node->exclude_set->head; c != nullptr; c = lnext(c)) {
            result->exclude_set_names.push_back(reinterpret_cast<duckdb_libpgquery::PGValue *>(c->data.ptr_value)->val.str);
        }
    }

    auto opt_col_node = PGPointerCast<duckdb_libpgquery::PGPredictFeatExpr>(root.opt_feat);
    
    if (opt_col_node  && opt_col_node->input_set) {
        for (auto c = opt_col_node->input_set->head; c != nullptr; c = lnext(c)) {
            result->opt_set_names.push_back(reinterpret_cast<duckdb_libpgquery::PGValue *>(c->data.ptr_value)->val.str);
        }
    }

    if (opt_col_node  && opt_col_node->exclude_set) {
        for (auto c = opt_col_node->exclude_set->head; c != nullptr; c = lnext(c)) {
            result->exclude_opt_set_names.push_back(reinterpret_cast<duckdb_libpgquery::PGValue *>(c->data.ptr_value)->val.str);
        }
    }

    for (auto c = root.result_set->head; c != nullptr; c = lnext(c)) {
        auto cdef = PGPointerCast<duckdb_libpgquery::PGColumnDef>(c->data.ptr_value);
        auto centry = TransformColumnDefinition(*cdef);
        if (cdef->constraints) {
            throw ParserException("Result set must not contain constraints!");
        }
        result->result_set_names.push_back(centry.GetName());
        result->result_set_types.push_back(centry.GetType());
    }

	SetQueryLocation(*result, root.location);
	return std::move(result);
}

} // namespace duckdb
