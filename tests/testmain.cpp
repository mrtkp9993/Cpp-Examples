#define CATCH_CONFIG_MAIN

#include "../src/bbpTypeFormula.h"
#include "../src/binom.h"
#include "../src/brentSalaminFormula.h"
#include "../src/devrandom.h"
#include "../src/discreteFourierTransform.h"
#include "../src/dualNumbers.h"
#include "../src/fixedPointIteration.h"
#include "../src/integerFactorization.h"
#include "../src/knapsack.h"
#include "../src/lagrangeInterpolation.h"
#include "../src/lcg.h"
#include "../src/metropolisHastings.h"
#include "../src/numericalIntegration.h"
#include "../src/rungeKutta.h"
#include "../src/statistics.h"
#include "../src/subsetSumProblem.h"
#include "Catch2/catch.hpp"

TEST_CASE("BBP-Type formula", "[BBP]") {
  std::vector<int> A{4, 0, 0, -2, -1, -1, 0, 0};
  REQUIRE((int)(P(1, 16, 8, A, 10) * 10000) / 10000.0 == 3.1415);
  REQUIRE((int)(P(1, 4, 2, std::vector<int>{1, 0}, 10) * 10000) / 10000.0 ==
          1.0986);
}

TEST_CASE("Binom formula", "[Binom]") { REQUIRE(binomCoef(4, 2) == 6); }

TEST_CASE("Brent-Salamin Formula", "[Brent-Salamin]") {
  auto appr_pi = calc_pi<long double>(15);
  REQUIRE(std::abs(M_PI - appr_pi) < 1e-17);
}

TEST_CASE("/dev/random RNG", "[devRandom]") {
  auto randInt = devrandom<int>();
  auto randDouble = devrandom<double>();
  REQUIRE(sizeof(randInt) == 4);
  REQUIRE(sizeof(randDouble) == 8);
}

TEST_CASE("Fixed point iteration", "[fixedpoint]") {
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

TEST_CASE("Composite Simpson", "[compositeSimpson]") {
  double a = 0.0;
  double b = M_PI;
  unsigned long n = 6;
  std::function<double(double)> func = [](double x) {
    return std::pow(x, 2) * std::cos(x);
  };
  double res = compositeSimpsons(a, b, n, func);
  REQUIRE(std::abs(res - (-6.27)) < 1e-2);
}

TEST_CASE("Double Simpson", "[doubleSimpson]") {
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

TEST_CASE("Normal random generator", "[normalRandom]") {
  std::vector<long double> nums(1000, 0);
  for (unsigned int i = 0; i < nums.size(); i++) {
    nums[i] = rnorm();
  }
  REQUIRE(jb_test(nums) == true);
}

TEST_CASE("Pollard rho algorithm", "[rho]") {
  REQUIRE(rho<long>(455459) == 743);
}

TEST_CASE("0-1 Knapsack Problem", "[01knapsack]") {
  SECTION("Problem 1") {
    uint n1 = 5;
    uint W1 = 11;
    vec v1({1, 6, 18, 22, 28});
    vec w1({1, 2, 5, 6, 7});
    REQUIRE(Knapsack01(v1, w1, n1, W1) == 40);
  }
  SECTION("Problem 2") {
    uint n2 = 3;
    uint W2 = 50;
    vec v2({60, 100, 120});
    vec w2({10, 20, 30});
    REQUIRE(Knapsack01(v2, w2, n2, W2) == 220);
  }
}

TEST_CASE("Monte-Carlo Integration", "[MonteCarloIntegration]") {
  long double a2 = 0.8;
  long double b2 = 3;
  unsigned long n2 = 100000;
  std::function<long double(long double)> func2 = [](long double x) {
    return 1 / (1 + std::sinh(2 * x) * std::pow(std::log(x), 2));
  };
  auto res = monteCarloIntegration(a2, b2, n2, func2);
  REQUIRE(std::abs(res - 0.67) < 1e-2);
}

TEST_CASE("Metropolis-Hastings Algorithm", "[MetropolishHastings]") {
  std::function<long double(long double)> target = [](long double x) {
    return x < 0 ? 0 : std::exp(-x);
  };
  std::vector<long double> nums = generate(target, 10000, 2500);
  auto average = std::accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
  std::cout << average << std::endl;
  REQUIRE(std::abs(average - 1.0) < 1e-1);
}

TEST_CASE("Subset-sum Problem", "[SubsetSum]") {
  SECTION("TRUE") {
    Set set = {1, 2, 4, 6};
    int target = 10;
    REQUIRE(subsetSum(set, target) == true);
  }
  SECTION("FALSE") {
    Set set = {1, 5, 7, 11};
    int target = 3;
    REQUIRE(subsetSum(set, target) == false);
  }
}

TEST_CASE("Lagrange Interpolation", "[Lagrange]") {
  SECTION("Data 1") {
    Data data{std::vector<long double>{-2, 5, 10},
              std::vector<long double>{9, -12, 33}};
    auto poly = lagrangePoly(data);
    REQUIRE(poly(2) == -15);
  }

  SECTION("Data 2") {
    Data data{std::vector<long double>{0, 1, 3, 4, 7},
              std::vector<long double>{1, 3, 49, 129, 813}};
    auto poly = lagrangePoly(data);
    REQUIRE(std::abs(poly(0.3) - 1.83) < 1e-2);
  }
}

TEST_CASE("Discrete Fourier Transform", "[DFT]") {
  CVec<> input({1, 2, 3});
  auto res = idft(dft(input));
  REQUIRE(std::abs(input[0].real() - res[0].real()) < 1e-2);
  REQUIRE(std::abs(input[1].real() - res[1].real()) < 1e-2);
  REQUIRE(std::abs(input[2].real() - res[2].real()) < 1e-2);
}

TEST_CASE("Auto diff with dual numbers", "[Dual]") {
  SECTION("Function1") {
    Dual x1(2, 1);
    Dual y1(2);
    Dual f1 = pow(x1, 2) * log(y1);
    REQUIRE(std::abs(f1.dual - 2.77) < 1e-2);
  }
  SECTION("Function2") {
    Dual x2(1, 1);
    Dual y2(2);
    Dual f2 = root(x2, 3) * cosh(x2) * cos(y2);
    REQUIRE(std::abs(f2.dual + 0.70) < 1e-2);
  }
  SECTION("Function3") {
    Dual x3(1);
    Dual y3(-1, 1);
    Dual f3 = sin(x3) * exp(y3) * tan(y3);
    REQUIRE(std::abs(f3.dual - 0.57) < 1e-2);
  }
  SECTION("Function4") {
    Dual x4(-2);
    Dual y4(3, 1);
    Dual f4 = sinh(x4) * tanh(y4);
    REQUIRE(std::abs(f4.dual + 0.03) < 1e-2);
  }
  SECTION("Function5") {
    Dual x5(0.1, 1);
    Dual y5(0.1);
    Dual f5 = asin(x5) * acos(x5) * atan(y5);
    REQUIRE(std::abs(f5.dual - 0.13) < 1e-2);
  }
}