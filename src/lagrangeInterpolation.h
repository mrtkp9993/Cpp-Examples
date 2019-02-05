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

/** A struct for storing x and y values. */
struct Data {
  Data(std::vector<long double> x, std::vector<long double> y) {
    assert(x.size() == y.size());
    this->x = x;
    this->y = y;
    this->size = x.size();
  }

  std::vector<long double> x;
  std::vector<long double> y;
  unsigned long size;
};

/**
 * Lagrange polynomial.
 *
 * @param data A data.
 *
 * @return Lagrange interpolation polynomial.
 */
std::function<long double(long double)> lagrangePoly(Data data);

#endif  // LAGRANGEINTERPOLATION_H
