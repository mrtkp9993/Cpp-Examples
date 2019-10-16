/**
 * @file binom.h
 *
 * @brief Calculate binomial coefficient.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef BINOM_H
#define BINOM_H

#include <cmath>

namespace CommonMath {
/**
 * @brief Calculate binomial coefficient.
 *
 * @param n An integer.
 * @param k An integer.
 *
 * @return Binomial coefficient.
 *
 */
template <typename T = unsigned long long int>
T binomCoef(const unsigned long &n, const unsigned long &k) {
  auto nCk = std::tgamma(n + 1) / (std::tgamma(n - k + 1) * std::tgamma(k + 1));
  return nCk;
}
}  // namespace CommonMath
#endif /* BINOM_H */
