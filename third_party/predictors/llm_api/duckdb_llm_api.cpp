#include "duckdb_llm_api.hpp"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>

#include "PerfEvent.hpp"

namespace duckdb {
LlmApiPredictor::LlmApiPredictor() : Predictor() {
}

/**
 * Configure the predictor. Reads the options set in `CREATE MODEL` 
 * via `options` parameter or use the defaults set in the client configs.
 *
 * Called only once per query before LlmApiPredictor::Load() is being called.
 *
 * @param client_config contains default or manually set configs.
 * @param options map of overrides for the client configs set when model is uploaded.
 */
void LlmApiPredictor::Config(const ClientConfig &client_config, const case_insensitive_map_t<Value> &options) {
    this->batch_size = (options.find("batch_size") != options.end()) ? IntegerValue::Get(options.at("batch_size")) : client_config.ml_batch_size;
	this->llm_max_tokens = (options.find("llm_max_tokens") != options.end()) ? IntegerValue::Get(options.at("llm_max_tokens")) : client_config.llm_max_tokens;

	// TODO: Implement any configurations here.
}

/**
 * Loads the models required by the predictor.
 *
 * Called only once per query before LlmApiPredictor::PredictChunk() calls.
 *
 * @param model_path path of the model set in `CREATE MODEL`.
 * @param stats statistics for profiling. Method should update `load` with the time this method use.
 */
void LlmApiPredictor::Load(const std::string &model_path, unique_ptr<PredictStats> &stats) {
#if OPT_TIMING
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif
	D_ASSERT(this->task == PredictorTask::PREDICT_LLM_API_TASK);

	// This would be the specific model name or API URL.
	this->model_path = model_path;

	// TODO: Implement API initialization here. Done once per query before executing it.

#if OPT_TIMING
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	stats->load = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
#endif
}

/**
 * Infer the models for a chunk (column vectors containing tupes).
 *
 * Called multiple times until all the tuples from child operator is covered.
 *
 * @param input chunk containing the output of child operator.
 * @param output chunk we should produce (predicted columns vectors).
 * @param rows number of rows in the input chunk (= output chunk).
 * @param input_mask vector of ids (of feature columns) which are use by the model.
 * @param output_size number of prediction columns.
 * @param stats statistics for profiling. Method should update `predict` with the time this method use.
 */
void LlmApiPredictor::PredictChunk(DataChunk &input, DataChunk &output, int rows, const std::vector<idx_t> &input_mask,
								 int output_size, unique_ptr<PredictStats> &stats) {
 	// Implemented to support mini-batches (i.e., batch_size < vector_size).
	// However, unless changed, batch_size == vector_size by default.
	// Check `ml_batch_size` in ClientConfig at `src/include/duckdb/main/client_config.hpp`
	int rounds = rows / batch_size;
	if (rows % batch_size != 0)
		rounds++;

	for (size_t batch = 0; batch < rounds; batch++) {
#if OPT_TIMING
		std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif

		int frow = batch * batch_size;						// Offset of first row
		int lrow = std::min(frow + batch_size, rows);		// Offset of last row
		int num_rows = lrow - frow;							// Number of rows in the batch

		std::array<int64_t, 2> input_shape_ {num_rows, (long long)input_mask.size()};
		std::array<int64_t, 2> output_shape_ {num_rows, output_size};

		// TODO: Change to accomodate input and output of the LLM call.
		// Currently, vectors of columns are converted to a single row-major vector.
		// The following initialize (float) vectors for input and output
		// Populate the input vector with tuple data (of projected feature columns) 
		// from the `input` chunk.
		int cols = input_mask.size();
		std::vector<float> input_data(num_rows * cols);
		int input_idx = 0;
		for (auto &idx : input_mask) {
			float *start = (float *)input.data[idx].GetData();

			float *dest = input_data.data() + input_idx;
			for (int i = 0; i < num_rows; ++i) {
				*(dest + i * cols) = *(start + i + frow);
			}
			input_idx++;
		}

		std::vector<float> output_data(num_rows * output_size, 0);

#if OPT_TIMING
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		stats->move += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

		begin = std::chrono::steady_clock::now();
#endif

		// TODO: Make the LLM API call, here.
		// Update the `output_data` vector.

#if OPT_TIMING
		end = std::chrono::steady_clock::now();
		stats->predict += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

		begin = std::chrono::steady_clock::now();
#endif

		// TODO: Change to accomodate to the output of the LLM call.
		// Currently, it update the `output` chunk with the values of `output_data` vector.
		// The following converts the single row-major output vector to column vectors.
		auto out_data_ptr = output_data.data();
		for (idx_t idx = 0; idx < output_size; idx++) {
			float *float_pointer = out_data_ptr + idx;
			data_ptr_t start = data_ptr_cast(float_pointer);

			auto dest = output.data[idx].GetData();
			for (int i = 0; i < num_rows; ++i) {
				*((float *)dest + i + frow) = *((float *)start + i * output_size);
			}
		}

#if OPT_TIMING
		end = std::chrono::steady_clock::now();
		stats->move_rev += std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
#endif
	}
}

}
