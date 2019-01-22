/**
 * @file statistics.cpp
 *
 * @brief Statistics related functions.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#include "statistics.h"

/**
 * @brief Uniform number generator.
 *
 * @param a Lower bound.
 * @param b Upper bound.
 *
 * @return A random number between [a, b].
 *
 */
double runif(const double& a, const double& b) {
  return a + (b - a) * (rand() / ((double)RAND_MAX + 1));
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
double rnorm(const double& mean, const double& sd) {
  // Box-Muller transform
  double u = runif(0, 1);
  double v = runif(0, 1);
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
double pchisq(const double& stat, const unsigned int& k) {
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
bool jb_test(const std::vector<double>& x) {
  const unsigned long n = x.size();
  double m1 = std::accumulate(x.begin(), x.end(), 0.0) / n;
  double m2 = 0;
  double m3 = 0;
  double m4 = 0;
  for (auto xi : x) {
    m2 += std::pow(xi - m1, 2);
    m3 += std::pow(xi - m1, 3);
    m4 += std::pow(xi - m1, 4);
  }
  m2 /= n;
  m3 /= n;
  m4 /= n;

  const double S = std::pow(m3 / std::pow(m2, 3 / 2), 2);
  const double K = m4 / std::pow(m2, 2);
  const double stat = n * (S / 6 + std::pow(K - 3, 2) / 24);
  const double p_val = 1 - pchisq(stat, 2);
  if (p_val > 0.05) {
    return true;
  } else {
    return false;
  }
}