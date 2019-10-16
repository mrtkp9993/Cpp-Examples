/**
 * @file integerFactorization.h
 *
 * @brief Implements Pollard rho algorithm.
 *
 * Pollard's rho algorithm is an algorithm for integer factorization. It was
 * invented by John Pollard in 1975.[1] It uses only a small amount of space,
 * and its expected running time is proportional to the square root of the size
 * of the smallest prime factor of the composite number being factorized.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 26/Jan/2019.
 *
 */

#ifndef INTEGERFACTORIZATION_H
#define INTEGERFACTORIZATION_H

#include <cmath>

namespace IntegerFactorization {
/**
 * @brief Helper function for generate a pseudo-random sequence.
 *
 * @tparam T A type.
 * @param x Input.
 * @param n The number which will be factorized.
 *
 * @return Pseudo-random number.
 *
 */
template <typename T>
T g(T x, T n) {
  return (T)(std::pow(x, 2) + 1) % n;
}

/**
 * @brief Greatest common divisor.
 *
 * @tparam T A type.
 * @param x Number 1.
 * @param y Number 2.
 *
 * @return GCD of x and y.
 *
 */
template <typename T>
T gcd(T x, T y) {
  return (y == 0) ? x : gcd(y, x % y);
}

/**
 * @brief Pollard rho algorithm.
 * @tparam T A type.
 * @param n The number which will be factorized.
 *
 * @return A non-trivial factor of n.
 */
template <typename T>
T rho(T n) {
  T x = 2;
  T y = 2;
  T d = 1;
  while (d == 1) {
    x = g<T>(x, n);
    y = g<T>(g<T>(y, n), n);
    d = gcd<T>(std::abs(x - y), n);
  }
  if (d == n) {
    throw "Fail";
  } else {
    return d;
  }
}
}  // namespace IntegerFactorization
#endif  // INTEGERFACTORIZATION_H
