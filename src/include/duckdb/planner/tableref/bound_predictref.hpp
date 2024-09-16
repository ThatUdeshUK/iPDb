//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/planner/tableref/bound_predictref.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/planner/binder.hpp"
#include "duckdb/planner/bound_tableref.hpp"

namespace duckdb {

struct BoundPredictInfo {
    uint8_t model_type;
    string model_name;
    //! The path of the model
    string model_path;
    //! The set of types
    vector<LogicalType> types;
    //! Input mask for feature column
    vector<idx_t> input_mask;
    //! Input mask for (optional) edges columns for GNN
    vector<idx_t> opt_mask;
    //! Result set names
    vector<string> result_set_names;
    //! Input set types
    vector<LogicalType> input_set_types;
    //! Result set types
    vector<LogicalType> result_set_types;

    void Serialize(Serializer &serializer) const;
    static BoundPredictInfo Deserialize(Deserializer &deserializer);
};

class BoundPredictRef : public BoundTableRef {
public:
	static constexpr const TableReferenceType TYPE = TableReferenceType::PREDICT;

public:
	explicit BoundPredictRef() : BoundTableRef(TableReferenceType::PREDICT) {
	}

    idx_t bind_index;
    //! The binder used to bind the child of the predict
    shared_ptr<Binder> child_binder;
    //! The binder used to bind the optional child for predict
	shared_ptr<Binder> opt_binder;
	//! The child node of the Predict
	vector<unique_ptr<BoundTableRef>> children;
    //! The bound predict info
    BoundPredictInfo bound_predict;
};
} // namespace duckdb
