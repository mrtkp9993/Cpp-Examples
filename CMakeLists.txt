cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 11)

project(numericCpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB sourcefiles src/*.cpp src/*.h)
include_directories(lib)

set(CATCH_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

add_executable(BBP src/bbpTypeFormula.cpp examples/BBPTypeFormula/main.cpp)
add_executable(BrentSalaminFormula src/brentSalaminFormula.h examples/BrentSalaminFormula/main.cpp)
add_executable(EigenExamples examples/EigenExamples/main.cpp)
add_executable(FixedPointIteration src/fixedPointIteration.cpp examples/FixedPointIteration/main.cpp)
add_executable(GoldenSectionSearch src/goldenSectionSearch.cpp examples/GoldenSectionSearch/main.cpp)
add_executable(LagrangeInterpolation src/lagrangeInterpolation.cpp examples/LagrangeInterpolation/main.cpp)
add_executable(Knapsack src/knapsack.cpp examples/Knapsack/main.cpp)
add_executable(IntegerFactorization src/integerFactorization.h examples/IntegerFactorization/main.cpp)
add_executable(MetropolisHastings src/statistics.cpp src/metropolisHastings.cpp examples/MetropolisHastings/main.cpp)
add_executable(NumericalIntegration src/statistics.cpp src/numericalIntegration.cpp examples/NumericalIntegration/main.cpp)
add_executable(PolynomialRoot src/polyroot.cpp examples/polyroot/main.cpp)
add_executable(RandomNumberGeneration src/statistics.cpp src/devrandom.h src/lcg.cpp examples/RandomNumberGenerators/main.cpp)
add_executable(RungeKuttaMethod src/rungeKutta.cpp examples/RungeKutta/main.cpp)
add_executable(SubsetSumProblem src/subsetSumProblem.cpp examples/SubsetSumProblem/main.cpp)

set(TEST_SOURCES ${PROJECT_SOURCE_DIR}/tests/testmain.cpp)
add_executable(tests ${sourcefiles} ${TEST_SOURCES})
target_link_libraries(tests Catch)
set_target_properties(tests
        PROPERTIES
        COMPILE_FLAGS "-ftest-coverage -fprofile-arcs"
        LINK_FLAGS    "-lgcov --coverage"
        )
