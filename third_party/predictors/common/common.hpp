#pragma once

#include "duckdb/common/types/vector.hpp"

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

    static LogicalTypeId type_to_logical_type(std::string type) {
        if (type == "VARCHAR") {
            return LogicalTypeId::VARCHAR;
        } else if (type == "INTEGER") {
            return LogicalTypeId::INTEGER;
        } else if (type == "BOOLEAN" || type == "BOOL") {
            return LogicalTypeId::BOOLEAN;
        }  else {
            throw InternalException("Unsupported column type");
        }   
    }

    void process_prompt_and_extract_types(std::vector<std::pair<std::string, LogicalTypeId>> &attrs, std::string &prompt) {
		static const std::regex out_re(R"((\w+)\s+(INTEGER|VARCHAR|BOOLEAN|BOOL))", std::regex_constants::icase);
        auto words_begin = std::sregex_iterator(prompt.begin(), prompt.end(), out_re);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            std::string match_str = match.str();
            auto attr = match[1].str();
			auto type = match[2].str();
            auto pos = prompt.find(match_str);
            prompt.replace(pos, match_str.size(), attr);
            attrs.push_back(std::make_pair(attr, type_to_logical_type(type)));
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

    void extract_data(const std::string &llm_out, int row, DataChunk &output, const PredictInfo &info) {
        auto out_json = nlohmann::json::parse(llm_out);
        for (size_t j = 0; j < info.result_set_names.size(); j++) {
            auto output_type = info.result_set_types[j];
            auto col_name = info.result_set_names[j];
            if (output_type == LogicalTypeId::VARCHAR && out_json[col_name].is_string()) {
                std::string value = out_json[col_name].get<std::string>();
                output.SetValue(j, row, Value(value));
            } else if (output_type == LogicalTypeId::INTEGER && out_json[col_name].is_string()) {
                auto value = extract_longest_integer(out_json[col_name].get<std::string>());
                output.SetValue(j, row, value);
            } else if (output_type == LogicalTypeId::INTEGER && out_json[col_name].is_number()) {
                int value = out_json[col_name].get<int>();
                output.SetValue(j, row, Value(value));
            } else if (output_type == LogicalTypeId::BOOLEAN && out_json[col_name].is_boolean()) {
				bool value = out_json[col_name].get<bool>();
                output.SetValue(j, row, Value(value));
			}  else {
                output.SetValue(j, row, Value(output_type));
            }
        }
    }
};

}