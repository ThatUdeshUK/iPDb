if(ENABLE_PREDICT)
  if (PREDICTOR_IMPL STREQUAL "torchscript")
    message(
      STATUS "Added TorchScript include directories")
    include_directories(${LIBTORCH_INCLUDE_DIRS})
    include_directories(../../third_party/predictors/torchscript/include)
  endif ()
  if (PREDICTOR_IMPL STREQUAL "onnx")
    message(
      STATUS "Added ORT include lib in src -> ${ONNX_RUNTIME_SESSION_INCLUDE_DIRS}")
    include_directories(${ONNX_RUNTIME_SESSION_INCLUDE_DIRS})
    include_directories(../../third_party/predictors/onnx/include)
  endif()
  if (PREDICTOR_IMPL STREQUAL "llama_cpp")
    message(
      STATUS "Added LLaMa.cpp include directories")
    include_directories(../../third_party/predictors/llama_cpp/include)
  endif()
endif()

add_subdirectory(expression_executor)
add_subdirectory(nested_loop_join)
add_subdirectory(operator)
add_subdirectory(physical_plan)
add_subdirectory(index)

add_library_unity(
  duckdb_execution
  OBJECT
  adaptive_filter.cpp
  aggregate_hashtable.cpp
  base_aggregate_hashtable.cpp
  column_binding_resolver.cpp
  expression_executor.cpp
  expression_executor_state.cpp
  join_hashtable.cpp
  perfect_aggregate_hashtable.cpp
  physical_operator.cpp
  physical_plan_generator.cpp
  radix_partitioned_hashtable.cpp
  reservoir_sample.cpp
  window_executor.cpp
  window_segment_tree.cpp)
set(ALL_OBJECT_FILES
    ${ALL_OBJECT_FILES} $<TARGET_OBJECTS:duckdb_execution>
    PARENT_SCOPE)
