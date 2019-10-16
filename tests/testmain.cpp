#define CATCH_CONFIG_MAIN

#include "../lib/numericCppExamples.hpp"
#include "Catch2/catch.hpp"

TEST_CASE("BBP-Type formula", "[BBP]") {
  std::vector<int> A{4, 0, 0, -2, -1, -1, 0, 0};
  REQUIRE((int)(Spigot::P(1, 16, 8, A, 10) * 10000) / 10000.0 == 3.1415);
  REQUIRE((int)(Spigot::P(1, 4, 2, std::vector<int>{1, 0}, 10) * 10000) /
              10000.0 ==
          1.0986);
}

TEST_CASE("Binom formula", "[Binom]") {
  REQUIRE(CommonMath::binomCoef(4, 2) == 6);
}

TEST_CASE("Brent-Salamin Formula", "[Brent-Salamin]") {
  auto appr_pi = Approximations::calc_pi<long double>(15);
  REQUIRE(std::abs(M_PI - appr_pi) < 1e-17);
}

TEST_CASE("/dev/random RNG", "[devRandom]") {
  auto randInt = RandomNumberGenerators::devrandom<int>();
  auto randDouble = RandomNumberGenerators::devrandom<double>();
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
  REQUIRE((int)(RootFinding::fixedPointIter(p0, tol, N0, g) * 100000) /
              100000.0 ==
          1.85558);
}

TEST_CASE("Golden Section Search", "[golden]") {
  long double a = 0;
  long double b = 1;
  const long double tol = 1e-12;
  auto func = [](long double x) { return std::pow(x, 2) - std::sin(x); };
  auto res = RootFinding::GoldenSectionSearch(a, b, tol, func);
  REQUIRE(std::abs(res.a - 0.4501836113524) < 1e-10);
  REQUIRE(std::abs(res.b - 0.4501836113532) < 1e-10);
}

TEST_CASE("Linear Congurent Generator", "[lcg]") {
  std::vector<int> rndArr = RandomNumberGenerators::lcg(7, 10, 7, 7, 4);
  REQUIRE(rndArr == std::vector<int>{7, 6, 9, 0});
}

TEST_CASE("Composite Simpson", "[compositeSimpson]") {
  double a = 0.0;
  double b = M_PI;
  unsigned long n = 6;
  std::function<double(double)> func = [](double x) {
    return std::pow(x, 2) * std::cos(x);
  };
  double res = NumericalIntegration::compositeSimpsons(a, b, n, func);
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
  double res =
      NumericalIntegration::doubleIntegral(a1, b1, m1, n1, c, d, func1);
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
  double w = ODE::RK4(a, b, N, init, func);
  REQUIRE(std::abs(w - 5.30) < 1e-2);
}

TEST_CASE("Normal random generator", "[normalRandom]") {
  std::vector<long double> nums(1000, 0);
  for (unsigned int i = 0; i < nums.size(); i++) {
    nums[i] = Statistics::rnorm();
  }
  REQUIRE(Statistics::jb_test(nums) == true);
}

TEST_CASE("Pollard rho algorithm", "[rho]") {
  REQUIRE(IntegerFactorization::rho<long>(455459) == 743);
}

TEST_CASE("Monte-Carlo Integration", "[MonteCarloIntegration]") {
  long double a2 = 0.8;
  long double b2 = 3;
  unsigned long n2 = 100000;
  std::function<long double(long double)> func2 = [](long double x) {
    return 1 / (1 + std::sinh(2 * x) * std::pow(std::log(x), 2));
  };
  auto res = NumericalIntegration::monteCarloIntegration(a2, b2, n2, func2);
  REQUIRE(std::abs(res - 0.67) < 1e-2);
}

TEST_CASE("Metropolis-Hastings Algorithm", "[MetropolishHastings]") {
  std::function<long double(long double)> target = [](long double x) {
    return x < 0 ? 0 : std::exp(-x);
  };
  std::vector<long double> nums = MCMC::generate(target, 10000, 2500);
  auto average = std::accumulate(nums.begin(), nums.end(), 0.0) / nums.size();
  std::cout << average << std::endl;
  REQUIRE(std::abs(average - 1.0) < 1e-1);
}

TEST_CASE("Lagrange Interpolation", "[Lagrange]") {
  SECTION("Data 1") {
    Interpolation::Data<long double> data{std::vector<long double>{-2, 5, 10},
                                          std::vector<long double>{9, -12, 33}};
    auto poly = Interpolation::lagrangePoly(data);
    REQUIRE(poly(2) == -15);
  }

  SECTION("Data 2") {
    Interpolation::Data<long double> data{
        std::vector<long double>{0, 1, 3, 4, 7},
        std::vector<long double>{1, 3, 49, 129, 813}};
    auto poly = lagrangePoly(data);
    REQUIRE(std::abs(poly(0.3) - 1.83) < 1e-2);
  }
}

TEST_CASE("Discrete Fourier Transform", "[DFT]") {
  IntegralTransforms::CVec<> input({1, 2, 3});
  auto res = IntegralTransforms::idft(IntegralTransforms::dft(input));
  REQUIRE(std::abs(input[0].real() - res[0].real()) < 1e-2);
  REQUIRE(std::abs(input[1].real() - res[1].real()) < 1e-2);
  REQUIRE(std::abs(input[2].real() - res[2].real()) < 1e-2);
}

TEST_CASE("Auto diff with dual numbers", "[Dual]") {
  SECTION("Function1") {
    AutoDiff::Dual x1(2, 1);
    AutoDiff::Dual y1(2);
    AutoDiff::Dual f1 = pow(x1, 2) * log(y1);
    REQUIRE(std::abs(f1.dual - 2.77) < 1e-2);
  }
  SECTION("Function2") {
    AutoDiff::Dual x2(1, 1);
    AutoDiff::Dual y2(2);
    AutoDiff::Dual f2 = root(x2, 3) * cosh(x2) * cos(y2);
    REQUIRE(std::abs(f2.dual + 0.70) < 1e-2);
  }
  SECTION("Function3") {
    AutoDiff::Dual x3(1);
    AutoDiff::Dual y3(-1, 1);
    AutoDiff::Dual f3 = sin(x3) * exp(y3) * tan(y3);
    REQUIRE(std::abs(f3.dual - 0.57) < 1e-2);
  }
  SECTION("Function4") {
    AutoDiff::Dual x4(-2);
    AutoDiff::Dual y4(3, 1);
    AutoDiff::Dual f4 = sinh(x4) * tanh(y4);
    REQUIRE(std::abs(f4.dual + 0.03) < 1e-2);
  }
  SECTION("Function5") {
    AutoDiff::Dual x5(0.1, 1);
    AutoDiff::Dual y5(0.1);
    AutoDiff::Dual f5 = asin(x5) * acos(x5) * atan(y5);
    REQUIRE(std::abs(f5.dual - 0.13) < 1e-2);
  }
}