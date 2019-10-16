/**
 * @file lagrangeInterpolation.h
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

#ifndef LAGRANGEINTERPOLATION_H
#define LAGRANGEINTERPOLATION_H

#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

namespace Interpolation {
/** A struct for storing x and y values. */
template <typename T = long double>
struct Data {
  Data(std::vector<T> x, std::vector<T> y) {
    assert(x.size() == y.size());
    this->x = x;
    this->y = y;
    this->size = x.size();
  }

  std::vector<T> x;
  std::vector<T> y;
  unsigned long size;
};

/**
 * Lagrange polynomial.
 *
 * @param data A data.
 *
 * @return Lagrange interpolation polynomial.
 */
template <typename T>
std::function<T(T)> lagrangePoly(const Data<T> &data) {
  auto polynomial = [data](T x) {
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
}  // namespace Interpolation
#endif  // LAGRANGEINTERPOLATION_H
