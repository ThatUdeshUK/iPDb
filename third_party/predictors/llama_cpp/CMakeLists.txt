cmake_minimum_required(VERSION 3.5)

project(duckdb_llama_cpp CXX)
if(POLICY CMP0063)
    cmake_policy(SET CMP0063 NEW)
endif()

set(CMAKE_CXX_STANDARD 17)

find_path(UTF8PROC_INCLUDE_DIRS utf8proc.h HINTS "$ENV{UTF8PROC_INSTALL_PREFIX}/include")
message(STATUS "UTF8LIB Include Libs: ${UTF8PROC_INCLUDE_DIRS}")

find_library(UTF8PROC_LIB utf8proc HINTS "$ENV{UTF8PROC_INSTALL_PREFIX}/lib")
message(STATUS "UTF8LIB Libs: ${UTF8PROC_LIB}")

find_library(LIBLLAMA_LIB llama HINTS "$ENV{LIBLLAMA_INSTALL_PREFIX}/bin")
message(STATUS "LLAMA_LIB Libs: ${LIBLLAMA_LIB}")

include_directories(include ${DUCKDB_MODULE_BASE_DIR}/third_party/httplib)

add_library(duckdb_llama_cpp STATIC duckdb_llama_cpp.cpp https_client.cpp)

target_link_libraries(duckdb_llama_cpp PUBLIC ${UTF8PROC_LIB} ${LIBLLAMA_LIB})
target_include_directories(duckdb_llama_cpp PUBLIC ${UTF8PROC_INCLUDE_DIRS})

set_target_properties(duckdb_llama_cpp PROPERTIES EXPORT_NAME duckdb_llama_cpp)

install(TARGETS duckdb_llama_cpp
        EXPORT "${DUCKDB_EXPORT_SET}"
        LIBRARY DESTINATION "${INSTALL_LIB_DIR}"
        ARCHIVE DESTINATION "${INSTALL_LIB_DIR}")

disable_target_warnings(duckdb_llama_cpp)
