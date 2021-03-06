cmake_minimum_required(VERSION 2.8.9)
cmake_policy(SET CMP0048 NEW)

project(utilcpp-math VERSION 0.2.0)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

if(BUILD_TYPE STREQUAL "Travis")
	set(CMAKE_BUILD_TYPE Debug)
	include(CodeCoverage)
	set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
	set(CMAKE_C_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
	add_subdirectory(tests)
else()
	set(CMAKE_BUILD_TYPE Release)
endif(BUILD_TYPE STREQUAL "Travis")

add_subdirectory(src)
add_subdirectory(example)
