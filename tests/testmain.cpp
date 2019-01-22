#define CATCH_CONFIG_MAIN

#include <cmath>
#include "../src/bbpTypeFormula.h"
#include "../src/binom.h"
#include "../src/devrandom.h"
#include "../src/fixedPointIteration.h"
#include "../src/goldenSectionSearch.h"
#include "../src/lcg.h"
#include "../src/metropolisHastings.h"
#include "../src/numericalIntegration.h"
#include "../src/polyroot.h"
#include "../src/rungeKutta.h"
#include "../src/statistics.h"
#include "Catch2/catch.hpp"

TEST_CASE("BBP-Type formula", "[bbp]") {
  std::vector<int> A{4, 0, 0, -2, -1, -1, 0, 0};
  REQUIRE((int)(P(1, 16, 8, A, 10) * 10000) / 10000.0 == 3.1415);
  REQUIRE((int)(P(1, 4, 2, std::vector<int>{1, 0}, 10) * 10000) / 10000.0 ==
          1.0986);
}

TEST_CASE("Binom formula", "[bnm]") { REQUIRE(binomCoef(4, 2) == 6); }

TEST_CASE("/dev/random RNG", "[dev]") {
  auto randInt = devrandom<int>();
  auto randDouble = devrandom<double>();
  REQUIRE(sizeof(randInt) == 4);
  REQUIRE(sizeof(randDouble) == 8);
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

TEST_CASE("Golden Section Search", "[gss]") {
  std::function<double(double)> func = [](double x) {
    return std::pow(x - 2, 2);
  };
  double a = 1;
  double b = 5;
  double tol = 1e-5;
  Result res = GoldenSectionSearch(a, b, tol, func);
  REQUIRE(std::abs(res.a - 1.99) < 1e-2);
  REQUIRE(std::abs(res.b - 2.00) < 1e-2);
}

TEST_CASE("Linear Congurent Generator", "[lcg]") {
  std::vector<int> rndArr = lcg(7, 10, 7, 7, 4);
  REQUIRE(rndArr == std::vector<int>{7, 6, 9, 0});
}

TEST_CASE("Composite Simpson", "[csi]") {
  double a = 0.0;
  double b = M_PI;
  unsigned long n = 6;
  std::function<double(double)> func = [](double x) {
    return std::pow(x, 2) * std::cos(x);
  };
  double res = compositeSimpsons(a, b, n, func);
  REQUIRE(std::abs(res - (-6.27)) < 1e-2);
}

TEST_CASE("Double Simpson", "[dsi]") {
  unsigned long m1 = 6;
  unsigned long n1 = 6;
  double a1 = 0.0;
  double b1 = M_PI_4;
  std::function<double(double)> c = [](double x) { return std::sin(x); };
  std::function<double(double)> d = [](double x) { return std::cos(x); };
  std::function<double(double, double)> func1 = [](double x, double y) {
    return 2 * y * std::sin(x) + std::pow(std::cos(x), 2);
  };
  double res = doubleIntegral(a1, b1, m1, n1, c, d, func1);
  REQUIRE(std::abs(res - 0.51) < 1e-2);
}

TEST_CASE("Polynomial roots", "[pol]") {
  double a = 1;
  double b = -1;
  double c = -1;
  std::vector<double> coef = {a, b, c};
  std::vector<double> roots = polyroot(coef);
  REQUIRE(std::abs(roots.at(0) - 1.618) < 1e-3);
  REQUIRE(std::abs(roots.at(1) + 0.618) < 1e-3);
}

TEST_CASE("Runge Kutta method", "[rk4]") {
  unsigned int N = 10;
  double a = 0.0;
  double b = 2.0;
  double init = 0.5;
  std::function<double(double, double)> func = [](double t, double y) {
    return y - std::pow(t, 2) + 1;
  };
  double w = RK4(a, b, N, init, func);
  REQUIRE(std::abs(w - 5.30) < 1e-2);
}

TEST_CASE("Normal random generator", "[nor]") {
  std::vector<double> nums(1000, 0);
  for (unsigned int i = 0; i < nums.size(); i++) {
    nums[i] = rnorm();
  }
  REQUIRE(jb_test(nums) == true);
}