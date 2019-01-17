#define CATCH_CONFIG_MAIN

#include <cmath>
#include "Catch2/catch.hpp"
#include "../src/BBPTypeFormula.h"
#include "../src/FixedPointIteration.h"

TEST_CASE("BBP-Type formula", "[bbp]") {
    REQUIRE((int)(P(1, 16, 8, std::vector<int>{4, 0, 0, -2, -1, -1, 0, 0}, 10) * 10000) / 10000.0 == 3.1415);
    REQUIRE((int)(P(1, 4, 2, std::vector<int>{1, 0}, 10) * 10000) / 10000.0 == 1.0986);
}

TEST_CASE("Fixed point iteration", "[fpi]") {
    double p0 = 2.0;
    double tol = 1e-5;
    unsigned long N0 = 100;
    std::function<double(double)> g = [](double x) {
        return std::pow(x + 10, 0.25);
    };
    REQUIRE((int)(fixedPointIter(p0, tol, N0, g) * 100000) / 100000.0 == 1.85558);
}