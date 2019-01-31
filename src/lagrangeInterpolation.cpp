/**
 * @file lagrangeInterpolation.cpp
 *
 * @brief Lagrange Interpolation.
 *
 * In numerical analysis, Lagrange polynomials are used for polynomial
 * interpolation. For a given set of points {\displaystyle (x_{j},y_{j})} with
 * no two x_{j} values equal, the Lagrange polynomial is the polynomial of
 * lowest degree that assumes at each value x_{j} the corresponding value y_{j}
 * (i.e. the functions coincide at each point).
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 31/Jan/2019.
 *
 */

#include "lagrangeInterpolation.h"

/**
 * Lagrange polynomial.
 *
 * @param data A data.
 *
 * @return Lagrange interpolation polynomial.
 */
std::function<double(double)> lagrangePoly(Data data) {
  auto polynomial = [data](double x) {
    auto sum = 0.0;
    for (auto j = 0; j < data.size; j++) {
      auto yj = data.y[j];
      auto inner_prod = 1.0;
      for (auto k = 0; k < data.size; k++) {
        if (k != j) {
          inner_prod *= (x - data.x[k]) / (data.x[j] - data.x[k]);
        }
      }
      sum += yj * inner_prod;
    };
    return sum;
  };

  return polynomial;
}