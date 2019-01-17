#define CATCH_CONFIG_MAIN

#include <cmath>
#include "../src/bbpTypeFormula.h"
#include "../src/binom.h"
#include "../src/cubicSplineInterpolation.h"
#include "../src/devrandom.h"
#include "../src/finiteDifferences.h"
#include "../src/fixedPointIteration.h"
#include "../src/lcg.h"
#include "Catch2/catch.hpp"

TEST_CASE("BBP-Type formula", "[bbp]") {
  std::vector<int> A{4, 0, 0, -2, -1, -1, 0, 0};
  REQUIRE((int)(P(1, 16, 8, A, 10) * 10000) / 10000.0 == 3.1415);
  REQUIRE((int)(P(1, 4, 2, std::vector<int>{1, 0}, 10) * 10000) / 10000.0 ==
          1.0986);
}

TEST_CASE("Binom formula", "[bnm]") { REQUIRE(binomCoef(4, 2) == 6); }

TEST_CASE("Cubic Spline Interpolation", "[cbi]") {
  Inputs inputs;
  inputs.n = 3;
  inputs.x = {0.0, 1.0, 2.0, 3.0};
  inputs.y = {1.0, 2.71, 7.39, 20.1};
  Solution sol = natCubicSplineInterpolation(inputs);
  REQUIRE((sol.a.at(0) - 24.09) < 1e-2);
  REQUIRE((sol.b.at(0) - 1.45) < 1e-2);
  REQUIRE((sol.c.at(0) - 0) < 1e-2);
  REQUIRE((sol.d.at(0) - 0.25) < 1e-2);
}

TEST_CASE("/dev/random RNG", "[dev]") {
  auto randInt = devrandom<int>();
  auto randDouble = devrandom<double>();
  REQUIRE(sizeof(randInt) == 4);
  REQUIRE(sizeof(randDouble) == 8);
}

TEST_CASE("Finite differences", "[dif]") {
  std::vector<double> arr = {10.0, 14.5, 22.0};
  std::vector<double> diff = forwardDifference(arr, 1);
  REQUIRE(diff == std::vector<double>{4.5, 7.5});
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

TEST_CASE("Linear Congurent Generator", "[lcg]") {
  std::vector<int> rndArr = lcg(7, 10, 7, 7, 4);
  REQUIRE(rndArr == std::vector<int>{7, 6, 9, 0});
}