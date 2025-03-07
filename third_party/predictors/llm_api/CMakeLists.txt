cmake_minimum_required(VERSION 3.5)

project(duckdb_llm_api CXX)
if(POLICY CMP0063)
    cmake_policy(SET CMP0063 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)

find_path(UTF8PROC_INCLUDE_DIRS utf8proc.h HINTS "$ENV{UTF8PROC_INSTALL_PREFIX}/include")
message(STATUS "UTF8LIB Include Libs: ${UTF8PROC_INCLUDE_DIRS}")

find_library(UTF8PROC_LIB utf8proc HINTS "$ENV{UTF8PROC_INSTALL_PREFIX}/lib")
message(STATUS "UTF8LIB Libs: ${UTF8PROC_LIB}")

include_directories(include)
add_library(duckdb_llm_api STATIC duckdb_llm_api.cpp)

target_link_libraries(duckdb_llm_api PUBLIC ${UTF8PROC_LIB})
target_include_directories(duckdb_llm_api PUBLIC ${UTF8PROC_INCLUDE_DIRS})

set_target_properties(duckdb_llm_api PROPERTIES EXPORT_NAME duckdb_llm_api)

install(TARGETS duckdb_llm_api
        EXPORT "${DUCKDB_EXPORT_SET}"
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}"
        ARCHIVE DESTINATION "${INSTALL_LIB_DIR}")

disable_target_warnings(duckdb_llm_api)
