cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

project(numericCpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB sourcefiles lib/*.hpp)
include_directories(include)

set(CATCH_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

set(TEST_SOURCES ${PROJECT_SOURCE_DIR}/tests/testmain.cpp)
add_executable(tests ${sourcefiles} ${TEST_SOURCES})
target_link_libraries(tests Catch)
set_target_properties(tests
        PROPERTIES
        COMPILE_FLAGS "-ftest-coverage -fprofile-arcs"
        LINK_FLAGS    "-lgcov --coverage"
        )
