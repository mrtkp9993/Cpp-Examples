/**
 * @file polyroot.cpp
 *
 * @brief Quadratic formula.
 *
 * Quadratic Formula  is the solution of
 * the quadratic equation.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#include "polyroot.h"
#include <cmath>   // abs, ceil, log, max, pow
#include <limits>  // infinity, quite_NAN

/**
 * @brief Quadratic formula.
 *
 * @param coef Coefficient vector.
 *
 * @return Roots of quadratic equation.
 *
 */
std::vector<double> polyroot(const std::vector<double>& coef) {
  std::vector<double> roots = {std::numeric_limits<double>::infinity(),
                               std::numeric_limits<double>::infinity()};
  double a = coef.at(0);
  double b = coef.at(1);
  double c = coef.at(2);
  double sigma = std::max(std::abs(a), std::max(std::abs(b), std::abs(c)));
  if (sigma == 0.0) {
    roots = {
        std::numeric_limits<double>::quiet_NaN(),
        std::numeric_limits<double>::quiet_NaN()};  // All Scalars are solutions
  } else {
    // Scale by power of 2 to avoid rounding errors
    sigma = std::pow(2.0, std::ceil(std::log(sigma) / std::log(2.0)));

    // Scale to avoid unnecessary overflow
    a /= sigma;
    b /= sigma;
    c /= sigma;

    // a may underflow; at most one root
    if (std::abs(a) == 0) {
      if (std::abs(b) == 0) {
        roots = {std::numeric_limits<double>::quiet_NaN(),
                 std::numeric_limits<double>::quiet_NaN()};  // no solutions
      } else {
        roots = {std::numeric_limits<double>::quiet_NaN(),
                 c / b};  // one solution
      }

    } else {
      b = (-b) / (2.0 * a);
      c /= a;
      double delta = b * b - c;  // discriminant
      if (delta >= 0.0) {
        // two real roots
        double sqrt_delta = std::sqrt(delta);
        double root1 = b + (b > 0.0 ? sqrt_delta : -sqrt_delta);
        double root2 = (std::abs(root1) > 0.0 ? c / root1 : 0.0);
        roots = {root1, root2};
      } else {
        // two complex roots
        double sqrt_neg_delta = std::sqrt(-delta);
        double root1_real = b;
        double root1_img = sqrt_neg_delta;
        double root2_real = b;
        double root2_img = -sqrt_neg_delta;
        roots = {root1_real, root1_img, root2_real, root2_img};
      }
    }
  }
  return roots;
}
