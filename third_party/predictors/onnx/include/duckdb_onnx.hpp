#pragma once

#include <onnxruntime_cxx_api.h>

#include <string>
#include <memory>
#include <map>
#include "duckdb/common/types/data_chunk.hpp"
#include "duckdb/common/types/vector.hpp"
#include "duckdb/execution/operator/projection/physical_predict.hpp"
#include <tokenizer.hpp>

#define ROW_FIRST_SET 0
#define COL_FIRST_SET 1
#define ROW_FIRST_COPY 2
#define COL_FIRST_COPY 3
#define ROW_FIRST_PUSH 4

#define MOVE_METHOD COL_FIRST_COPY
#define MOVE_REV_METHOD COL_FIRST_COPY

#define DYNAMIC_TOKEN_SIZE 0

#define OPT_TIMING 1

namespace duckdb {
class ONNXPredictor: public Predictor {
public:
    ONNXPredictor();

    int execution_mode;
    int intra_tc;
    int inter_tc;

public:
    void Config(const ClientConfig &config) override;
    void Load(const std::string &model_path, PredictStats &stats) override;
    void Predict(std::vector<float> &input, std::vector<float> &output, int output_size) override;
    void PredictChunk(DataChunk &input, DataChunk &output, int rows, const std::vector<idx_t> &input_mask, int output_size, PredictStats &stats) override;
    void PredictLM(std::string &input, std::vector<float> &output, int output_size) override;
    void PredictLMChunk(DataChunk &input, DataChunk &output, int rows, const std::vector<idx_t> &input_mask, int output_size, PredictStats &stats) override;
    void PredictGNN(vector<float> &nodes, vector<int64_t> &edges, vector<float> &output,
					int64_t num_nodes, int64_t num_edges, int64_t feature_size, int64_t edge_size,
					int64_t output_size, PredictStats &stats) override;
private:
    Ort::Session session{nullptr};
    FullTokenizer tokenizer;
    
    void Preprocess(const std::string &text, int64_t* input_ids, int64_t* mask, int offset, int max_length) const;
    void Preprocess2(const std::vector<long> &text, int64_t* input_ids, int64_t* mask, int offset, int max_length) const;
};
} // namespace duckdb
