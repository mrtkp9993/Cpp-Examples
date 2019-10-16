/**
 * @file numericalIntegration.h
 *
 * @brief Numerical integration methods.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef NUMERICALINTEGRATION_H
#define NUMERICALINTEGRATION_H

#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <numeric>
#include "statistics.h"

namespace NumericalIntegration {
/**
 * @brief Composite Simpson’s Integration.
 *
 * Composite Simpson is a method for the
 * numerical approximation of definite integrals.
 *
 * @param a Endpoint.
 * @param b Endpoint.
 * @param n Iteration count.
 * @param func The function that will be integrated.
 *
 * @return Approximation to integral.
 *
 */
template <typename T = long double>
T compositeSimpsons(const T &a, const T &b, const unsigned long &n,
                    const std::function<T(T)> &func) {
  auto XI = 0.0;
  // STEP 1
  auto h = (b - a) / n;
  // STEP 2
  auto XI0 = func(a) + func(b);
  auto XI1 = 0.0;
  auto XI2 = 0.0;
  // STEP 3
  for (auto i = 1; i <= n - 1; i++) {
    // STEP 4
    auto X = a + i * h;
    // STEP 5
    if (i % 2 == 0) {
      XI2 = XI2 + func(X);
    } else {
      XI1 = XI1 + func(X);
    }
  }
  XI = h * (XI0 + 2 * XI2 + 4 * XI1) / 3;
  std::cout << "Approximation to integral: " << XI << std::endl;
  return XI;
}

/**
 * @brief Double Simpson’s Integration.
 *
 * Double Simpson is a method for the
 * numerical approximation of double integrals.
 *
 * @param a Endpoint.
 * @param b Endpoint.
 * @param m Iteration count.
 * @param n Iteration count.
 * @param c A function.
 * @param d A function.
 * @param func The function that will be integrated.
 *
 * @return Approximation to integral.
 *
 */
template <typename T = long double>
T doubleIntegral(const T &a, const T &b, const unsigned long &m,
                 const unsigned long &n, const std::function<T(T)> &c,
                 const std::function<T(T)> &d,
                 const std::function<T(T, T)> &func) {
  assert(m % 2 == 0);
  assert(n % 2 == 0);
  auto J = 0.0;
  // STEP 1
  auto h = (b - a) / n;
  auto J1 = 0.0;
  auto J2 = 0.0;
  auto J3 = 0.0;
  // STEP 2
  for (auto i = 0; i <= n; i++) {
    // STEP 3
    auto x = a + i * h;
    auto cx = c(x);
    auto dx = d(x);
    auto HX = (dx - cx) / m;
    auto K1 = func(x, cx) + func(x, dx);
    auto K2 = 0.0;
    auto K3 = 0.0;
    // STEP 4
    for (auto j = 1; j <= m - 1; j++) {
      // STEP 5
      auto y = cx + j * HX;
      auto Q = func(x, y);
      // STEP 6
      if (j % 2 == 0) {
        K2 += Q;
      } else {
        K3 += Q;
      }
    }
    // STEP 7
    auto L = (K1 + 2 * K2 + 4 * K3) * HX / 3;
    // STEP 8
    if (i == 0 || i == n) {
      J1 += L;
    } else if (i % 2 == 0) {
      J2 += L;
    } else {
      J3 += L;
    }
  }
  // STEP 9
  J = h * (J1 + 2 * J2 + 4 * J3) / 3;
  std::cout << "Approximation to integral: " << J << std::endl;
  return J;
}

/**
 * @brief Monte-Carlo Integration.
 *
 * Monte-Carlo Integration is a technique for numerical
 * integration using random numbers. It is a particular
 * Monte Carlo method that numerically computes a definite
 * integral.
 *
 * @param a Endpoint.
 * @param b Endpoint.
 * @param n Iteration count.
 * @param func The function that will be integrated.
 *
 * @return Approximation to integral.
 *
 */
template <typename T = long double>
T monteCarloIntegration(const T &a, const T &b, const unsigned long &n,
                        std::function<T(T)> &func) {
  std::vector<T> X(n, 0);
  for (auto i = 0; i < n; i++) {
    X[i] = Statistics::runif(a, b);
  }

  T sum = 0;
  for (auto xi : X) {
    sum += func(xi);
  }

  auto result = (b - a) / n * sum;

  std::cout << "Approximation to integral: " << result << std::endl;
  return result;
}
}  // namespace NumericalIntegration
#endif /* NUMERICALINTEGRATION_H */
