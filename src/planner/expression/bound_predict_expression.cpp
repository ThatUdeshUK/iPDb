#include "duckdb/planner/expression/bound_predict_expression.hpp"
#include "duckdb/parser/expression/predict_expression.hpp"
#include "duckdb/function/function_serialization.hpp"
#include "duckdb/common/serializer/serializer.hpp"
#include "duckdb/common/serializer/deserializer.hpp"

namespace duckdb {

BoundPredictExpression::BoundPredictExpression(LogicalType return_type, vector<unique_ptr<Expression>> children_p)
    : Expression(ExpressionType::PREDICT, ExpressionClass::PREDICT, std::move(return_type)), children(std::move(children_p)) {
	// D_ASSERT(!function.name.empty());
}


bool BoundPredictExpression::IsVolatile() const {
	return true;
}

bool BoundPredictExpression::IsConsistent() const {
	return false;
}

bool BoundPredictExpression::IsFoldable() const {
	return false;
}

bool BoundPredictExpression::CanThrow() const {
	return true;
}

string BoundPredictExpression::ToString() const {
	return bound_predict->result_set_names[0];
}

hash_t BoundPredictExpression::Hash() const {
	hash_t result = Expression::Hash();
	return result;
}

bool BoundPredictExpression::Equals(const BaseExpression &other_p) const {
	if (!Expression::Equals(other_p)) {
		return false;
	}
	auto &other = other_p.Cast<BoundPredictExpression>();
	// if (other.function != function) {
	// 	return false;
	// }
	if (!Expression::ListEquals(children, other.children)) {
		return false;
	}
	// if (!FunctionData::Equals(bind_info.get(), other.bind_info.get())) {
	// 	return false;
	// }
	return true;
}

bool BoundPredictExpression::PropagatesNullValues() const {
	return Expression::PropagatesNullValues();
}

unique_ptr<Expression> BoundPredictExpression::Copy() const {
	vector<unique_ptr<Expression>> new_children;
	new_children.reserve(children.size());
	for (auto &child : children) {
		new_children.push_back(child->Copy());
	}
	auto copy_info = bound_predict ? std::make_unique<BoundPredictInfo>() : nullptr;
	if (bound_predict) {
		copy_info->model_type = bound_predict->model_type;
		copy_info->model_name = bound_predict->model_name;
		copy_info->model_path = bound_predict->model_path;
		copy_info->base_api = bound_predict->base_api;
		copy_info->prompt = bound_predict->prompt;
		copy_info->input_set_names = bound_predict->input_set_names;
		copy_info->result_set_names = bound_predict->result_set_names;
		copy_info->input_set_types = bound_predict->input_set_types;
		copy_info->result_set_types = bound_predict->result_set_types;
	}

	auto copy = make_uniq<BoundPredictExpression>(return_type, std::move(new_children));
	copy->bound_predict = std::move(copy_info);
	copy->CopyProperties(*this);
	return std::move(copy);
}

void BoundPredictExpression::Serialize(Serializer &serializer) const {
	Expression::Serialize(serializer);
	serializer.WriteProperty(200, "return_type", return_type);
	serializer.WriteProperty(201, "children", children);
	// FunctionSerializer::Serialize(serializer, function, bind_info.get());
	// serializer.WriteProperty(202, "is_operator", is_operator);
}

unique_ptr<Expression> BoundPredictExpression::Deserialize(Deserializer &deserializer) {
	auto return_type = deserializer.ReadProperty<LogicalType>(200, "return_type");
	auto children = deserializer.ReadProperty<vector<unique_ptr<Expression>>>(201, "children");

	// auto entry = FunctionSerializer::Deserialize<ScalarFunction, ScalarFunctionCatalogEntry>(
	//     deserializer, CatalogType::SCALAR_FUNCTION_ENTRY, children, return_type);
	// auto function_return_type = entry.first.return_type;

	// auto is_operator = deserializer.ReadProperty<bool>(202, "is_operator");

	// if (entry.first.bind_expression) {
	// 	// bind the function expression
	// 	auto &context = deserializer.Get<ClientContext &>();
	// 	auto bind_input = FunctionBindExpressionInput(context, entry.second, children);
	// 	// replace the function expression with the bound expression
	// 	auto bound_expression = entry.first.bind_expression(bind_input);
	// 	if (bound_expression) {
	// 		return bound_expression;
	// 	}
	// 	// Otherwise, fall thorugh and continue on normally
	// }
	auto result = make_uniq<BoundPredictExpression>(return_type, std::move(children));
	// result->is_operator = is_operator;
	// if (result->return_type != return_type) {
	// 	// return type mismatch - push a cast
	// 	auto &context = deserializer.Get<ClientContext &>();
	// 	return BoundCastExpression::AddCastToType(context, std::move(result), return_type);
	// }
	return std::move(result);
}

} // namespace duckdb
