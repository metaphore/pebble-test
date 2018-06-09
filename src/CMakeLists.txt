cmake_minimum_required(VERSION 3.10)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/..)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
file(GLOB MainSources *.c *.h **/*.c **/*.h)
add_library(pebble-test ${MainSources})