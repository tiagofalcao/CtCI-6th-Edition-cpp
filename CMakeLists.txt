cmake_minimum_required(VERSION 2.8.8)
set(PROJECT_NAME_STR CtCI)
project(${PROJECT_NAME_STR} C CXX)

find_package(Threads REQUIRED)

if(CMAKE_COMPILER_IS_GNUCXX)
     set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -pthread")
     set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g3")
     set(CMAKE_CXX_FLAGS_RELEASE "-O3")
endif()

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(benchmark)
if(TARGET benchmark::benchmark)
    set(BENCHMARK_LIBRARIES benchmark::benchmark)
endif()

add_subdirectory(Ch01-ArraysAndStrings)
