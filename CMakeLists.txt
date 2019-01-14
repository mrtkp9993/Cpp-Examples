cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)

project(numericCpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

file(GLOB sourcefiles src/*.cpp src/*.h)
include_directories(lib)

add_executable(BBP ${sourcefiles} examples/BBPTypeFormula/main.cpp)
add_executable(CubicSplineInterpolation ${sourcefiles} examples/CubicSplineInterpolation/main.cpp)
add_executable(EigenExamples ${sourcefiles} examples/EigenExamples/main.cpp)
add_executable(FiniteDifferences ${sourcefiles} examples/finiteDifferences/main.cpp)
add_executable(FixedPointIteration ${sourcefiles} examples/FixedPointIteration/main.cpp)
add_executable(GoldenSectionSearch ${sourcefiles} examples/GoldenSectionSearch/main.cpp)
add_executable(NumericalIntegration ${sourcefiles} examples/NumericalIntegration/main.cpp)
add_executable(PolynomialRoot ${sourcefiles} examples/polyroot/main.cpp)
add_executable(RandomNumberGeneration ${sourcefiles} examples/RandomNumberGenerators/main.cpp)
add_executable(RungeKuttaMethod ${sourcefiles} examples/RungeKutta/main.cpp)