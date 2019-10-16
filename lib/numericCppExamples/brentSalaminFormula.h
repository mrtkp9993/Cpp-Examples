/**
 * @file brentSalaminFormula.h
 *
 * @brief Brent-Salamin Formula.
 *
 * The Brent-Salamin formula, also called the
 * Gauss-Salamin formula or Salamin formula, is
 * a formula that uses the arithmetic-geometric
 * mean to compute pi.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 24/Jan/2019.
 *
 */

#ifndef BRENTSALAMINFORMULA_H
#define BRENTSALAMINFORMULA_H

#include <cmath>
#include <vector>

using std::pow;
using std::sqrt;

namespace Approximations {
/**
 * @brief Brent-Salamin Formula.
 *
 * @tparam T Type of return value. Choose appropriate type for precision which
 * you want.
 * @param n_iter Iteration count.
 *
 * @return Approximation of pi.
 *
 */
template <typename T = long double>
T calc_pi(const unsigned int& n_iter) {
  T appr_pi = 0.0;
  std::vector<T> a(n_iter, 0);
  std::vector<T> b(n_iter, 0);
  std::vector<T> t(n_iter, 0);
  std::vector<T> p(n_iter, 0);

  a[0] = 1;
  b[0] = 1 / sqrt(2);
  t[0] = 1 / 4.0;
  p[0] = 1;

  for (auto i = 1; i < n_iter; i++) {
    a[i] = (a[i - 1] + b[i - 1]) / 2.0;
    b[i] = sqrt(a[i - 1] * b[i - 1]);
    t[i] = t[i - 1] - p[i - 1] * pow(a[i - 1] - a[i], 2);
    p[i] = p[i - 1] * 2;
  }

  appr_pi = pow(a[n_iter - 1] + b[n_iter - 1], 2) / (4 * t[n_iter - 1]);
  return appr_pi;
}
}  // namespace Approximations
#endif  // BRENTSALAMINFORMULA_H
