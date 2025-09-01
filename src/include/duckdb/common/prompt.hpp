#pragma once

#include "duckdb/common/types.hpp"

namespace duckdb {

class Prompt {
public:
    static constexpr char const *TYPE_STRING_NULL = "NULL";
	static constexpr char const *TYPE_STRING_BOOLEAN = "BOOLEAN";
	static constexpr char const *TYPE_STRING_INTEGER = "INTEGER";
	static constexpr char const *TYPE_STRING_DOUBLE = "DOUBLE";
	static constexpr char const *TYPE_STRING_VARCHAR = "VARCHAR";
	static constexpr char const *TYPE_STRING_ARRAY = "ARRAY";
	static constexpr char const *TYPE_STRING_OBJECT = "OBJECT";

    static constexpr char const *OUT_REGEX = R"((\w+)\s+(INTEGER|VARCHAR|BOOLEAN|BOOL|DOUBLE))";

    static LogicalTypeId type_to_logical_type(std::string type) {
        if (type == Prompt::TYPE_STRING_VARCHAR) {
            return LogicalTypeId::VARCHAR;
        } else if (type == Prompt::TYPE_STRING_INTEGER) {
            return LogicalTypeId::INTEGER;
        } else if (type == Prompt::TYPE_STRING_BOOLEAN || type == "BOOL") {
            return LogicalTypeId::BOOLEAN;
        } else if (type == Prompt::TYPE_STRING_DOUBLE) {
            return LogicalTypeId::DOUBLE;
        }  else {
            throw InternalException("Unsupported column type");
        }   
    }
};

}
