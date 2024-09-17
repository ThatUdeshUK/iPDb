#include "duckdb/common/enums/model_type.hpp"
#include "duckdb/common/enum_util.hpp"
#include "duckdb/execution/operator/projection/physical_predict.hpp"
#include "duckdb/execution/physical_plan_generator.hpp"
#include "duckdb/planner/operator/logical_predict.hpp"

namespace duckdb {

unique_ptr<PhysicalOperator> PhysicalPlanGenerator::CreatePlan(LogicalPredict &op) {
	switch (op.bound_predict.model_type) {
	case ModelType::TABULAR:
	case ModelType::LLM: {
		D_ASSERT(op.children.size() == 1);
		auto child_plan = CreatePlan(*op.children[0]);
		auto predict = make_uniq<PhysicalPredict>(std::move(op.types), std::move(child_plan));
		predict->model_type = op.bound_predict.model_type;
		predict->model_path = std::move(op.bound_predict.model_path);
		predict->input_mask = std::move(op.bound_predict.input_mask);
		predict->result_set_types = std::move(op.bound_predict.result_set_types);
		predict->options = std::move(op.bound_predict.options);
		return std::move(predict);
	}
	case ModelType::GNN: {
		D_ASSERT(op.children.size() == 2);
		idx_t node_cardinality = op.children[0]->EstimateCardinality(context);
		idx_t edge_cardinality = op.children[1]->EstimateCardinality(context);
		auto node_plan = CreatePlan(*op.children[0]);
		auto edge_plan = CreatePlan(*op.children[1]);
		auto predict = make_uniq<PhysicalGNNPredict>(std::move(op.types), node_cardinality);
		predict->children.push_back(std::move(node_plan));
		predict->children.push_back(std::move(edge_plan));
		predict->model_type = op.bound_predict.model_type;
		predict->model_path = std::move(op.bound_predict.model_path);
		predict->num_nodes = node_cardinality;
		predict->num_edges = edge_cardinality;
		predict->node_mask = std::move(op.bound_predict.input_mask);
		predict->edge_mask = std::move(op.bound_predict.opt_mask);
		predict->node_types = std::move(op.bound_predict.input_set_types);
		predict->result_set_types = std::move(op.bound_predict.result_set_types);
		predict->options = std::move(op.bound_predict.options);
		return std::move(predict);
	}
	default:
		throw InternalException("Plan Error: Unknown model type `" +
		                        std::string(EnumUtil::ToChars<ModelType>(op.bound_predict.model_type)));
	}
}

} // namespace duckdb
