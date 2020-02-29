cmake_minimum_required(VERSION 3.0)
project(recovery_block_for_multi_version_sorting)

set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/src)
aux_source_directory(${PROJECT_SOURCE_DIR}/src SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/tests TEST_SRCS)
aux_source_directory(${PROJECT_SOURCE_DIR}/demo DEMO_SRCS)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(demo ${SRCS} ${DEMO_SRCS})
add_executable(test ${SRCS} ${TEST_SRCS})
