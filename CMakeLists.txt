cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

project(numericCpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB sourcefiles src/*.cpp src/*.h)
include_directories(lib)

set(CATCH_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

add_executable(BBP ${sourcefiles} examples/BBPTypeFormula/main.cpp)
add_executable(BrentSalaminFormula ${sourcefiles} examples/BrentSalaminFormula/main.cpp)
add_executable(DiscreteFourierTransform ${sourcefiles} examples/DiscreteFourierTransform/main.cpp)
add_executable(EigenExamples examples/EigenExamples/main.cpp)
add_executable(FixedPointIteration ${sourcefiles} examples/FixedPointIteration/main.cpp)
add_executable(GoldenSectionSearch ${sourcefiles} examples/GoldenSectionSearch/main.cpp)
add_executable(LagrangeInterpolation ${sourcefiles} examples/LagrangeInterpolation/main.cpp)
add_executable(Knapsack ${sourcefiles} examples/Knapsack/main.cpp)
add_executable(IntegerFactorization ${sourcefiles} examples/IntegerFactorization/main.cpp)
add_executable(MetropolisHastings ${sourcefiles} examples/MetropolisHastings/main.cpp)
add_executable(NumericalIntegration ${sourcefiles} examples/NumericalIntegration/main.cpp)
add_executable(PolynomialRoot ${sourcefiles} examples/polyroot/main.cpp)
add_executable(RandomNumberGeneration ${sourcefiles} examples/RandomNumberGenerators/main.cpp)
add_executable(RungeKuttaMethod ${sourcefiles} examples/RungeKutta/main.cpp)
add_executable(SubsetSumProblem ${sourcefiles} examples/SubsetSumProblem/main.cpp)

set(TEST_SOURCES ${PROJECT_SOURCE_DIR}/tests/testmain.cpp)
add_executable(tests ${sourcefiles} ${TEST_SOURCES})
target_link_libraries(tests Catch)
set_target_properties(tests
        PROPERTIES
        COMPILE_FLAGS "-ftest-coverage -fprofile-arcs"
        LINK_FLAGS    "-lgcov --coverage"
        )
