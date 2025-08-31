cmake_minimum_required(VERSION 3.5)

project(duckdb_llm_api CXX)
if(POLICY CMP0063)
    cmake_policy(SET CMP0063 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)

find_package(OpenSSL REQUIRED)

include_directories(include ${DUCKDB_MODULE_BASE_DIR}/third_party/httplib ${OPENSSL_INCLUDE_DIR})

if (ENABLE_LLM_API)
    add_library(duckdb_llm_api STATIC duckdb_llm_api.cpp https_client.cpp)
    target_compile_definitions(duckdb_llm_api PRIVATE $<$<BOOL:${ENABLE_LLM_API}>:ENABLE_LLM_API>)
endif()

target_include_directories(
  duckdb_llm_api
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

set_target_properties(duckdb_llm_api PROPERTIES EXPORT_NAME duckdb_llm_api)

install(TARGETS duckdb_llm_api
        EXPORT "${DUCKDB_EXPORT_SET}"
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}"
        ARCHIVE DESTINATION "${INSTALL_LIB_DIR}")

disable_target_warnings(duckdb_llm_api)
