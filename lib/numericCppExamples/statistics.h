/**
 * @file statistics.h
 *
 * @brief Statistics related functions.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef STATISTICS_H
#define STATISTICS_H

#include <cmath>
#include <cstdlib>
#include <numeric>
#include <random>
#include <vector>

namespace Statistics {
/**
 * @brief Uniform number generator.
 *
 * @param a Lower bound.
 * @param b Upper bound.
 *
 * @return A random number between [a, b].
 *
 */
template <typename T = long double>
T runif(const T &a = 0, const T &b = 1) {
  return a + (b - a) * (rand() / ((T)(RAND_MAX) + 1));
}

/**
 * @brief Normal number generator with Box–Muller transform.
 *
 * Box–Muller transform is a pseudo-random number sampling
 * method for generating pairs of independent, standard,
 * normally distributed (zero expectation, unit variance)
 * random numbers, given a source of uniformly distributed
 * random numbers.
 *
 * @param mean Mean of distribution.
 * @param sd Standart deviation of distribution.
 *
 * @return A random number.
 *
 */
template <typename T = long double>
T rnorm(const T &mean = 0, const T &sd = 1) {
  // Box-Muller transform
  auto u = runif<T>(0, 1);
  auto v = runif<T>(0, 1);
  return sd * (std::sqrt(-2 * std::log(u)) * std::cos(2 * M_PI * v)) + mean;
}

/**
 * @brief Chi-Squared distribution.
 *
 *
 * @param stat Test statistic.
 * @param k Degrees of freedom.
 *
 * @return A probability.
 *
 */
template <typename T = long double>
T pchisq(const T &stat, const unsigned int &k) {
  return (1 / ((std::pow(2, k / 2) * std::tgamma(k / 2)))) *
         std::pow(stat, k / 2 - 1) * std::exp(-stat / 2);
}

/**
 * @brief Jarque–Bera test.
 *
 * Jarque–Bera test is a goodness-of-fit test of whether
 * sample data have the skewness and kurtosis matching
 * a normal distribution.
 *
 * @param x Vector of numbers.
 *
 * @return A boolean which indicates that x is normally distributed or not.
 *
 */
bool jb_test(const std::vector<long double> &x) {
  const unsigned long n = x.size();
  auto m1 = std::accumulate(x.begin(), x.end(), 0.0) / n;
  auto m2 = 0;
  auto m3 = 0;
  auto m4 = 0;
  for (auto xi : x) {
    m2 += std::pow(xi - m1, 2);
    m3 += std::pow(xi - m1, 3);
    m4 += std::pow(xi - m1, 4);
  }
  m2 /= n;
  m3 /= n;
  m4 /= n;

  auto S = std::pow(m3 / std::pow(m2, 3 / 2), 2);
  auto K = m4 / std::pow(m2, 2);
  auto stat = n * (S / 6 + std::pow(K - 3, 2) / 24);
  auto p_val = 1 - pchisq(stat, 2);
  return p_val > 0.05;
}
}  // namespace Statistics
#endif  // STATISTICS_H
