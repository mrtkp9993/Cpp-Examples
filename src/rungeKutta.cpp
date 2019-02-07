/**
 * @file rungeKutta.cpp
 *
 * @brief Runge-Kutta Order Four.
 *
 * Runge-Kutta methods are a family of implicit
 * and explicit iterative methods, which include
 * the well-known routine called the Euler Method,
 * used in temporal discretization for the
 * approximate solutions of ordinary differential equations.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#include "rungeKutta.h"

void formattedPrint(long double t, long double w);

/**
 * @brief Runge-Kutta Order Four.
 *
 * @param a Endpoint.
 * @param b Endpoint.
 * @param N Iteration count.
 * @param init Initial condition.
 * @param func A function.
 *
 * @return Approximation to exact solution.
 *
 */
long double RK4(
    const long double &a, const long double &b, const unsigned int &N,
    const long double &init,
    const std::function<long double(long double, long double)> &func) {
  // STEP 1
  auto h = (b - a) / N;
  auto t = a;
  auto w = init;
  formattedPrint(t, w);
  // STEP 2
  for (auto i = 1; i <= N; i++) {
    // STEP 3
    auto K1 = h * func(t, w);
    auto K2 = h * func(t + h / 2, w + K1 / 2);
    auto K3 = h * func(t + h / 2, w + K2 / 2);
    auto K4 = h * func(t + h, w + K3);
    // STEP 4
    w += (K1 + 2 * K2 + 2 * K3 + K4) / 6;
    t = a + i * h;
    // STEP 5
    formattedPrint(t, w);
  }
  return w;
}

void formattedPrint(long double t, long double w) {
  std::cout << t << "\t" << w << std::endl;
}
