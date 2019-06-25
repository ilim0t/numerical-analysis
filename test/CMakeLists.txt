cmake_minimum_required(VERSION 3.10)
include(CTest)

if (CMAKE_VERSION VERSION_LESS 3.2)
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "")
else ()
    set(UPDATE_DISCONNECTED_IF_AVAILABLE "UPDATE_DISCONNECTED 1")
endif ()

include(${PROJECT_SOURCE_DIR}/cmake/DownloadProject/DownloadProject.cmake)
download_project(
        PROJ                googletest
        GIT_REPOSITORY      https://github.com/google/googletest.git
        GIT_TAG             master
        ${UPDATE_DISCONNECTED_IF_AVAILABLE}
)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

if (CMAKE_VERSION VERSION_LESS 2.8.11)
    include_directories("${gtest_SOURCE_DIR}/include"
            "${gmock_SOURCE_DIR}/include")
endif ()

include(GoogleTest)

add_executable(NumericalAnalysisTest
        definition_test.cpp

        comparison_test.cpp
        calculation_test.cpp)

target_link_libraries(NumericalAnalysisTest
#        NumericalAnalysisLIB
        gtest
        gmock_main)

include_directories(${PROJECT_SOURCE_DIR}/src)

gtest_add_tests(TARGET NumericalAnalysisTest)
