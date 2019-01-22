/**
 * @file metropolisHastings.cpp
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

#include "metropolisHastings.h"

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
std::vector<double> generate(const std::function<double(double)>& target,
                             const unsigned int& count,
                             const unsigned int& burn_in_period) {
  std::srand(std::clock());

  std::vector<double> x(count + burn_in_period, 0);
  x[0] = 1;

  for (unsigned int i = 1; i < count + burn_in_period; i++) {
    double current_x = x[i - 1];
    double proposed_x = current_x + rnorm();
    double A = target(proposed_x) / target(current_x);
    if (runif() < A) {
      x[i] = proposed_x;
    } else {
      x[i] = current_x;
    }
  }

  x.erase(x.begin(), x.begin() + burn_in_period);

  return x;
}
