//===----------------------------------------------------------------------===//
//                         DuckDB
//
// duckdb/execution/operator/projection/physical_predict.hpp
//
//
//===----------------------------------------------------------------------===//

#pragma once

#include "duckdb/execution/physical_operator.hpp"
#include "duckdb/main/client_config.hpp"
#include "duckdb/common/common.hpp"
#include "duckdb/common/enums/model_type.hpp"
#include "duckdb/planner/expression.hpp"
#include "duckdb/planner/tableref/bound_predictref.hpp"

namespace duckdb {

typedef enum PredictorTask { 
	PREDICT_TABULAR_TASK = 0, 
	PREDICT_LM_TASK = 1, 
	PREDICT_GNN_TASK = 2, 
	PREDICT_LLM_TASK = 3 
} PredictorTask;

struct PredictStats {
	long load;
	long preprocess;
	long move;
	long predict;
	long move_rev;

	long correct;
	long total;
};

class Predictor {
public:
	Predictor() : success(false), error_message("") {};
	virtual ~Predictor() {};

	PredictorTask task;
	std::string model_path;
	std::string prompt;

	int batch_size;
	int llm_max_tokens; // LLM specific

	bool success;
	std::string error_message;

public:
	virtual void Config(const ClientConfig &config, const case_insensitive_map_t<Value> &options) {};
	virtual void Load(const std::string &model_path, unique_ptr<PredictStats> &stats) {};
	virtual void Predict(std::vector<float> &input, std::vector<float> &output, int output_size) {};
	virtual void PredictLM(std::string &input, std::vector<float> &output, int output_size) {};
	virtual void PredictLMChunk(DataChunk &input, DataChunk &output, int rows, const std::vector<idx_t> &input_mask,
	                            int output_size, unique_ptr<PredictStats> &stats) {};
	virtual void PredictVector(std::vector<float> &input, std::vector<float> &output, int rows, int cols,
	                           int output_size) {};
	virtual void PredictChunk(DataChunk &input, DataChunk &output, int rows, const std::vector<idx_t> &input_mask,
	                          int output_size, unique_ptr<PredictStats> &stats) {};
	virtual void PredictGNN(vector<float> &nodes, vector<int64_t> &edges, vector<float> &output,
	                        unique_ptr<PredictStats> &stats) {};
	virtual void PredictGNN(vector<float> &nodes, vector<int64_t> &edges, vector<float> &output, int64_t num_nodes,
	                        int64_t num_edges, int64_t feature_size, int64_t edge_size, int64_t output_size,
	                        unique_ptr<PredictStats> &stats) {};
};

//! PhysicalPredict implements the operator physical PREDICT operation
class PhysicalPredict : public PhysicalOperator {
public:
	PhysicalPredict(vector<LogicalType> types, PhysicalOperator &child, BoundPredictInfo bound_predict_p);

	ModelType model_type;
	string model_path;
	string prompt;

	std::vector<idx_t> input_mask;
	std::vector<LogicalType> result_set_types;
	case_insensitive_map_t<Value> options;

public:
	string GetName() const override;
	InsertionOrderPreservingMap<string> ParamsToString() const override;

public:
	unique_ptr<OperatorState> GetOperatorState(ExecutionContext &context) const override;
	OperatorResultType Execute(ExecutionContext &context, DataChunk &input, DataChunk &chunk,
	                           GlobalOperatorState &gstate, OperatorState &state_p) const override;

	bool ParallelOperator() const override {
		return false;
	}

private:
	unique_ptr<Predictor> InitPredictor() const;
};

//! PhysicalGNNPredict implements the source/sink physical PREDICT operation
class PhysicalGNNPredict : public PhysicalOperator {
public:
	static constexpr const PhysicalOperatorType TYPE = PhysicalOperatorType::PREDICT;

public:
	PhysicalGNNPredict(vector<LogicalType> types, PhysicalOperator &node_child, PhysicalOperator &edge_child,
					   idx_t node_cardinality, idx_t edge_cardinality, BoundPredictInfo bound_predict_p);

	ModelType model_type;
	string model_path;

	idx_t num_nodes;
	idx_t num_edges;
	vector<idx_t> node_mask;
	vector<idx_t> edge_mask;
	vector<LogicalType> node_types;
	vector<LogicalType> result_set_types;
	case_insensitive_map_t<Value> options;

public:
	void BuildPipelines(Pipeline &current, MetaPipeline &meta_pipeline) override;
	vector<const_reference<PhysicalOperator>> GetSources() const override;

public:
	// Source interface
	unique_ptr<GlobalSourceState> GetGlobalSourceState(ClientContext &context) const override;
	SourceResultType GetData(ExecutionContext &context, DataChunk &chunk, OperatorSourceInput &input) const override;

	bool IsSource() const override {
		return true;
	}

private:
	unique_ptr<Predictor> InitPredictor() const;

public:
	// Sink interface
	SinkResultType Sink(ExecutionContext &context, DataChunk &chunk, OperatorSinkInput &input) const override;
	SinkCombineResultType Combine(ExecutionContext &context, OperatorSinkCombineInput &input) const override;
	SinkFinalizeType Finalize(Pipeline &pipeline, Event &event, ClientContext &context,
	                          OperatorSinkFinalizeInput &input) const override;
	unique_ptr<LocalSinkState> GetLocalSinkState(ExecutionContext &context) const override;
	unique_ptr<GlobalSinkState> GetGlobalSinkState(ClientContext &context) const override;

	bool IsSink() const override {
		return true;
	}

	bool ParallelSink() const override {
		return true;
	}

	InsertionOrderPreservingMap<string> ParamsToString() const override;
};

} // namespace duckdb
