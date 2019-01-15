#define CATCH_CONFIG_MAIN

#include "Catch2/catch.hpp"
#include "../src/BBPTypeFormula.h"
#include "../src/cubicSplineInterpolation.h"
#include "../src/devrandom.h"
#include "../src/finiteDifferences.h"
#include "../src/FixedPointIteration.h"
#include "../src/GoldenSectionSearch.h"
#include "../src/LCG.h"
#include "../src/NumericalIntegration.h"
#include "../src/polyroot.h"
#include "../src/RungeKutta.h"

TEST_CASE("BBP-Type formula", "[bbp]") {
    REQUIRE((int)(P(1, 16, 8, std::vector<int>{4, 0, 0, -2, -1, -1, 0, 0}, 10) * 10000) / 10000.0 == 3.1415);
    REQUIRE((int)(P(1, 4, 2, std::vector<int>{1, 0}, 10) * 10000) / 10000.0 == 1.0986);
}