/**
 * @file lcg.h
 *
 * @brief Linear Congruential Generator.
 *
 * Linear Congruential Generator is an algorithm that yields
 * a sequence of pseudo–randomized numbers calculated with
 * a discontinuous piecewise linear equation. The method represents
 * one of the oldest and best–known pseudorandom number
 * generator algorithms.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef LCG_H
#define LCG_H

#include <stdio.h>
#include <cassert>
#include <cmath>
#include <vector>

namespace RandomNumberGenerators {
/**
 * @brief Linear Congruential Generator.
 *
 * @param seed Seed.
 * @param mod Modulus.
 * @param mult Multiplier.
 * @param incr Increment.
 * @param count Count of generated numbers.
 *
 * @return Vector of generated numbers.
 *
 */
template <typename T = int>
std::vector<T> lcg(const int& seed, const int& mod, const int& mult,
                   const int& incr, const int& count) {
  assert(mod > 0);
  assert(0 < mult < mod);
  assert(0 <= incr < mod);
  assert(0 <= seed < mod);
  std::vector<T> randInts(count);
  randInts[0] = seed;
  for (int n = 1; n < count; n++) {
    randInts[n] = (mult * randInts[n - 1] + incr) % mod;
  }
  return randInts;
}
}  // namespace RandomNumberGenerators
#endif /* LCG_H */
