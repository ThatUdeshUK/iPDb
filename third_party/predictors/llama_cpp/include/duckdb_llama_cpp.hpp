#pragma once

#include <string>
#include <memory>
#include <map>
#include "duckdb/common/types/data_chunk.hpp"
#include "duckdb/common/types/vector.hpp"
#include "duckdb/execution/operator/projection/physical_predict.hpp"
#include "duckdb/common/string_util.hpp"
#include "../../common/common.hpp"

#include "llama.h"

#define OPT_TIMING 1

namespace duckdb {
class LlamaCppPredictor: public Predictor {
public:
    int n_gl;
    int n_predict;
    std::string prompt;
    std::string base_api;
    std::string grammar;
    bool is_api;
    bool is_source = false;;

    llama_model * model;

    const llama_vocab * vocab;

    struct llama_sampler * grmr;
    struct llama_sampler * chain;
    
private:
    PromptUtil prompt_util;

public:
    LlamaCppPredictor(std::string prompt);
    ~LlamaCppPredictor() {
        if (!is_api) {
            llama_sampler_free(grmr);
            llama_sampler_free(chain);
            llama_model_free(model);
        }
    }

public:
    void Config(const ClientConfig &config, const case_insensitive_map_t<Value> &options) override;
    void Load(const std::string &model_path, unique_ptr<PredictStats> &stats) override;
    void PredictChunk(ClientContext &client, DataChunk &input, DataChunk &output, int rows, const PredictInfo &info, unique_ptr<PredictStats> &stats) override;
    void ScanChunk(ClientContext &client, DataChunk &output, const PredictInfo &info, unique_ptr<PredictStats> &stats) override;

private:
    void GenerateGrammar();
    void InitializeSampler();
};
} // namespace duckdb
