#include "duckdb/common/enums/model_type.hpp"
#include "duckdb/common/enum_util.hpp"
#include "duckdb/execution/operator/projection/physical_predict.hpp"
#include "duckdb/execution/physical_plan_generator.hpp"
#include "duckdb/planner/operator/logical_predict.hpp"

namespace duckdb {

PhysicalOperator &PhysicalPlanGenerator::CreatePlan(LogicalPredict &op) {
	switch (op.bound_predict.model_type) {
	case ModelType::TABULAR:
	case ModelType::LM:
	case ModelType::LLM: {
		D_ASSERT(op.children.size() == 1);
		auto &plan = CreatePlan(*op.children[0]);
		return Make<PhysicalPredict>(std::move(op.types), plan, std::move(op.bound_predict));
	}
	case ModelType::GNN: {
		D_ASSERT(op.children.size() == 2);
		idx_t node_cardinality = op.children[0]->EstimateCardinality(context);
		idx_t edge_cardinality = op.children[1]->EstimateCardinality(context);
		auto &node_plan = CreatePlan(*op.children[0]);
		auto &edge_plan = CreatePlan(*op.children[1]);
		return Make<PhysicalGNNPredict>(std::move(op.types), node_plan, edge_plan, node_cardinality, edge_cardinality, std::move(op.bound_predict));
	}
	default:
		throw InternalException("Plan Error: Unknown model type `" +
		                        std::string(EnumUtil::ToChars<ModelType>(op.bound_predict.model_type)));
	}
}

} // namespace duckdb
