/**
 * @file fixedPointIteration.h
 *
 * @brief Fixed point iteration.
 *
 * Fixed Point Iteration is a method of computing
 * fixed points of iterated functions. We can write
 * an equation f(x)=0 in x=g(x) form and we can
 * find this equation’s fixed point and solve first
 * equation.
 *
 * Algorithm 2.2 (Numerical Analysis, Ninth Edition, Burden, Faires)
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef FIXEDPOINTITERATION_H
#define FIXEDPOINTITERATION_H

#include <cmath>
#include <functional>
#include <iostream>

namespace RootFinding {
/**
 * @brief Find a solution to p = g(p) given an initial approximation p0.
 *
 * @param p0 Initial approximation.
 * @param tol Tolerance.
 * @param N0 Maximum number of iterations.
 * @param g The function.
 *
 * @return Approximate solution p or message of failure..
 *
 */
template <typename T = long double>
T fixedPointIter(T p0, const T &tol, const unsigned long &N0,
                 const std::function<T(T)> &g) {
  auto i = 1;
  while (i <= N0) {
    T p = g(p0);
    if (std::abs(p - p0) < tol) {
      std::cout << "Root found after " << i << " iterations: " << p
                << std::endl;
      return p;
    }
    i += 1;
    p0 = p;
  }
  std::cout << "The method failed after " << N0 << " iterations" << std::endl;
  return 0;
}
}  // namespace RootFinding
#endif /* FIXEDPOINTITERATION_H */
