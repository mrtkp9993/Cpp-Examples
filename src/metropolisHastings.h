/**
 * @file metropolisHastings.h
 *
 * @brief Metropolis-Hastings algorithm.
 *
 * Metropolis-Hastings Algorithm is a Markov chain Monte Carlo
 * (MCMC) method for obtaining a sequence of random samples
 * from a probability distribution from which direct sampling
 * is difficult. This sequence can be used to approximate
 * the distribution or to compute an integral.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef METROPOLISHASTINGS_H
#define METROPOLISHASTINGS_H

#include <ctime>
#include <functional>
#include <vector>
#include "../src/statistics.h"

/**
 * @brief Metropolis-Hastings algorithm.
 *
 * @param target The target distribution.
 * @param count Count of generated numbers.
 * @param burn_in_period Burn-in period.
 *
 * @return Vector of generated numbers.
 *
 */
std::vector<long double> generate(
    const std::function<long double(long double)> &target,
    const unsigned int &count, const unsigned int &burn_in_period);

#endif  // METROPOLISHASTINGS_H
