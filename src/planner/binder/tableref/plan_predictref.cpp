#include "duckdb/planner/tableref/bound_predictref.hpp"
#include "duckdb/planner/operator/logical_predict.hpp"

namespace duckdb {

unique_ptr<LogicalOperator> Binder::CreatePlan(BoundPredictRef &ref) {
	auto result = make_uniq<LogicalPredict>(ref.bind_index, std::move(ref.bound_predict));
	for (auto &child: ref.children) {
		auto subquery = ref.child_binder->CreatePlan(*child);
		D_ASSERT(subquery);

		result->AddChild(std::move(subquery));
	}
    return std::move(result);
}

} // namespace duckdb
