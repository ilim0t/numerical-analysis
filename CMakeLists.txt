cmake_minimum_required(VERSION 3.10)
project(numerical-analysis)

set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g3 -O0")

#enable_testing()

add_subdirectory(src)
add_subdirectory(test)

add_executable(numerical-analysis main.cpp)
#target_link_libraries(numerical-analysis NumericalAnalysisLIB)
target_include_directories(numerical-analysis PUBLIC src)
