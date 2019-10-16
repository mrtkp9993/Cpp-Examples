/**
 * @file bbpTypeFormula.h
 *
 * @brief BPP Type formula calculation.
 *
 * The Bailey–Borwein–Plouffe formula (BBP formula) is a
 * spigot algorithm which is an algorithm for computing
 * the value of a mathematical constant such as π or e
 * which generates output digits in some base
 * (usually 2 or a power of 2) from left to right,
 * with limited intermediate storage. The name comes from
 * the sense of the word "spigot" for a tap or valve
 * controlling the flow of a liquid.
 *
 * Formula was taken from:
 * https://bbp.carma.newcastle.edu.au/
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef BBPTYPEFORMULA_H
#define BBPTYPEFORMULA_H

#include <cassert>
#include <cmath>
#include <vector>

namespace Spigot {
/**
 * @brief BPP Type formula calculation.
 *
 * @param s An integer.
 * @param b An integer.
 * @param n An integer.
 * @param A A sequence of integers.
 * @param n_iter Iteration count.
 *
 * @return Approximation of a number.
 *
 */
template <typename T = long double>
T P(const int &s, const int &b, const int &n, const std::vector<int> &A,
    const int &n_iter) {
  assert(n == A.size());

  T result = 0.0;

  for (auto k = 0; k <= n_iter; k++) {
    T inv_bk = 1 / std::pow(b, k);
    T inner_sum = 0.0;
    for (auto j = 1; j <= n; j++) {
      inner_sum += A.at(j - 1) / std::pow(n * k + j, s);
    }
    result += inv_bk * inner_sum;
  }

  return result;
}
}  // namespace Spigot

#endif  // BBPTYPEFORMULA_H
