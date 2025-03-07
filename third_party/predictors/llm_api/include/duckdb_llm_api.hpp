#pragma once

#include <string>
#include <memory>
#include <map>
#include "duckdb/common/types/data_chunk.hpp"
#include "duckdb/common/types/vector.hpp"
#include "duckdb/execution/operator/projection/physical_predict.hpp"

#define OPT_TIMING 1

namespace duckdb {
class LlmApiPredictor: public Predictor {
public:
    LlmApiPredictor();

public:
    void Config(const ClientConfig &config, const case_insensitive_map_t<Value> &options) override;
    void Load(const std::string &model_path, unique_ptr<PredictStats> &stats) override;
    void PredictChunk(DataChunk &input, DataChunk &output, int rows, const std::vector<idx_t> &input_mask, int output_size, unique_ptr<PredictStats> &stats) override;

};
} // namespace duckdb
