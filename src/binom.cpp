/**
 * @file binom.cpp
 *
 * @brief Calculate binomial coefficient.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#include "binom.h"
#include <cmath>

/**
 * @brief Calculate binomial coefficient.
 *
 * @param n An integer.
 * @param k An integer.
 *
 * @return Binomial coefficient.
 *
 */
unsigned long binomCoef(const unsigned long &n, const unsigned long &k) {
  auto nCk = std::tgamma(n + 1) / (std::tgamma(n - k + 1) * std::tgamma(k + 1));
  return nCk;
}
