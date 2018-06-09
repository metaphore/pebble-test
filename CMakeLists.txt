cmake_minimum_required(VERSION 3.10)

project(pebble-test C)
set(PEBBLE_FLAVOUR diorite)
set(PEBBLE_SDK_VER 4.3)
set(PEBBLE_SDK_INCLUDE_DIR "$ENV{HOME}/.pebble-sdk/SDKs/${PEBBLE_SDK_VER}/sdk-core/pebble/${PEBBLE_FLAVOUR}/include")


include_directories("${PEBBLE_SDK_INCLUDE_DIR}")
# The generated files such as resource_ids are picked up from here:
include_directories("build/${PEBBLE_FLAVOUR}")
include_directories("build/include")
# Pebble libraries
include_directories("node_modules/@smallstoneapps/utils/dist/include")

add_subdirectory(src)

#set(CMAKE_C_STANDARD 99)