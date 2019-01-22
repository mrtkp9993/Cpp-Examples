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

void formattedPrint(double t, double w);

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
double RK4(const double& a, const double& b, const unsigned int& N,
           const double& init,
           const std::function<double(double, double)>& func) {
  // STEP 1
  double h = (b - a) / N;
  double t = a;
  double w = init;
  formattedPrint(t, w);
  // STEP 2
  for (int i = 1; i <= N; i++) {
    // STEP 3
    double K1 = h * func(t, w);
    double K2 = h * func(t + h / 2, w + K1 / 2);
    double K3 = h * func(t + h / 2, w + K2 / 2);
    double K4 = h * func(t + h, w + K3);
    // STEP 4
    w += (K1 + 2 * K2 + 2 * K3 + K4) / 6;
    t = a + i * h;
    // STEP 5
    formattedPrint(t, w);
  }
  return w;
}

void formattedPrint(double t, double w) {
  std::cout << t << "\t" << w << std::endl;
}
