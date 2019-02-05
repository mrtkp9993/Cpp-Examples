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
#include <vector>

/**
 * @brief Uniform number generator.
 *
 * @param a Lower bound.
 * @param b Upper bound.
 *
 * @return A random number between [a, b].
 *
 */
long double runif(const long double &a = 0, const long double &b = 1);

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
long double rnorm(const long double &mean = 0, const long double &sd = 1);

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
bool jb_test(const std::vector<long double> &x);

#endif  // STATISTICS_H
