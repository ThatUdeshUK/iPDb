#pragma once

#include "duckdb/common/types/vector.hpp"
#include "duckdb/common/prompt.hpp"

#include "nlohmann/json.hpp"  // nlohmann/json
#include <regex>
#include <iostream>

namespace duckdb {

class PromptUtil {
public:
    Value extract_longest_integer(const std::string& input) {
        std::regex re("\\d+");
        std::sregex_iterator it(input.begin(), input.end(), re);
        std::sregex_iterator end;

        std::string longest;
        for (; it != end; ++it) {
            if (it->str().size() > longest.size()) {
                longest = it->str();
            }
        }
        if (!longest.empty())
            return Value(std::stoi(longest));
        return Value(LogicalTypeId::INTEGER);
    }

    void process_prompt_and_extract_types(std::vector<std::pair<std::string, LogicalTypeId>> &attrs, std::string &prompt) {
		static const std::regex out_re(Prompt::OUT_REGEX, std::regex_constants::icase);
        auto words_begin = std::sregex_iterator(prompt.begin(), prompt.end(), out_re);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string match_str = match.str();
            auto attr = match[1].str();
			auto type = match[2].str();
            auto pos = prompt.find(match_str);
            attrs.push_back(std::make_pair(attr, Prompt::type_to_logical_type(type)));
        }
    }

    std::string embed_prompt(const std::string &prompt, int row, DataChunk &input, const PredictInfo &info) {
        std::stringstream ss;
        ss << prompt << ";\n";
        idx_t col_i = 0;
        for (auto mask_i : info.input_mask) {
            ss << info.input_set_names[col_i] << " = `";
            col_i++;
            ss <<  input.GetValue(mask_i, row).ToSQLString() << "`;\n";
        }
        return ss.str();
    }

    void extract_array_data(const std::string &llm_out, DataChunk &output, const PredictInfo &info) {
        auto out_json = nlohmann::json::parse(llm_out);
        if (out_json.is_array()) {
            output.SetCardinality(out_json.size());
            idx_t row = 0;
            for (nlohmann::json::iterator it = out_json.begin(); it != out_json.end(); ++it) {
                populate_row_data(*it, row, output, info);
                row++;
            }
        }
    }

    void extract_row_data(const std::string &llm_out, int row, DataChunk &output, const PredictInfo &info) {
        auto out_json = nlohmann::json::parse(llm_out);
        populate_row_data(out_json, row, output, info);
    }

    void populate_row_data(const nlohmann::json &out_json, int row, DataChunk &output, const PredictInfo &info) {
        for (size_t j = 0; j < info.result_set_names.size(); j++) {
            auto output_type = info.result_set_types[j];
            auto col_name = info.result_set_names[j];

            try {
                if (!out_json.contains(col_name)) {
                    output.SetValue(j, row, Value(output_type));
                    continue;
                }

                if (output_type == LogicalTypeId::VARCHAR && out_json[col_name].is_string()) {
                    std::string value = out_json[col_name].get<std::string>();
                    output.SetValue(j, row, Value(value));
                } else if (output_type == LogicalTypeId::INTEGER && out_json[col_name].is_string()) {
                    auto value = extract_longest_integer(out_json[col_name].get<std::string>());
                    output.SetValue(j, row, value);
                } else if (output_type == LogicalTypeId::INTEGER && out_json[col_name].is_number()) {
                    int value = out_json[col_name].get<int>();
                    output.SetValue(j, row, Value(value));
                } else if (output_type == LogicalTypeId::DOUBLE && out_json[col_name].is_number()) {
                    int value = out_json[col_name].get<double>();
                    output.SetValue(j, row, Value(value));
                } else if (output_type == LogicalTypeId::BOOLEAN && out_json[col_name].is_boolean()) {
                    bool value = out_json[col_name].get<bool>();
                    output.SetValue(j, row, Value(value));
                }  else {
                    output.SetValue(j, row, Value(output_type));
                }
            } catch (const nlohmann::json::parse_error& e) {
                std::cout << "JSON parse issue: " << e.what() << std::endl;
                output.SetValue(j, row, Value(output_type));
            }
        }
    }
};

}