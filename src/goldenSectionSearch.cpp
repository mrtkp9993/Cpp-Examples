/**
 * @file goldenSectionSearch.cpp
 *
 * @brief Golden Section Search.
 *
 * The golden-section search is a technique for
 * finding the extremum (minimum or maximum) of a
 * strictly unimodal function by successively narrowing
 * the range of values inside which the extremum is
 * known to exist. The technique derives its name from
 * the fact that the algorithm maintains the function
 * values for triples of points whose distances form
 * a golden ratio.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#include "goldenSectionSearch.h"

/**
 * @brief Golden Section Search.
 *
 * @param a Lower bound.
 * @param b Upper bound.
 * @param tol Tolerance.
 * @param func The function.
 *
 * @return The interval with d-c<=tol.
 *
 */
Result GoldenSectionSearch(double a, double b, const double& tol,
                           const std::function<double(double)>& func) {
  assert(a < b);
  assert(tol > 0);
  Result result = {.a = 0, .b = 0};
  const double inversePhi = (std::sqrt(5) - 1.0) / 2;   // 1 / phi
  const double inversePhi2 = (3.0 - std::sqrt(5)) / 2;  // 1 / phi^2
  double h = b - a;
  if (h <= tol) {
    result.a = a;
    result.b = b;
    return result;
  }
  auto n = (int)std::ceil(std::log(tol / h) / std::log(inversePhi));
  double c = a + inversePhi2 * h;
  double d = a + inversePhi * h;
  double yc = func(c);
  double yd = func(d);
  for (int k = 0; k < n - 1; k++) {
    if (yc < yd) {
      b = d;
      d = c;
      yd = yc;
      h = inversePhi * h;
      c = a + inversePhi2 * h;
      yc = func(c);
    } else {
      a = c;
      c = d;
      yc = yd;
      h = inversePhi * h;
      d = a + inversePhi * h;
      yd = func(d);
    }
  }
  if (yc < yd) {
    result.a = a;
    result.b = d;
    return result;
  } else {
    result.a = c;
    result.b = b;
    return result;
  }
}
