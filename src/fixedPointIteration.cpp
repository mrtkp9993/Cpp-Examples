/**
 * @file fixedPointIteration.cpp
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

 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#include "fixedPointIteration.h"

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
long double fixedPointIter(long double p0, const double &tol, const unsigned long &N0,
                           const std::function<long double(long double)> &g) {
  unsigned long i = 1;
  while (i <= N0) {
    long double p = g(p0);
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
