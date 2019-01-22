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
std::vector<int> lcg(const int& seed, const int& mod, const int& mult,
                     const int& incr, const int& count);

#endif /* LCG_H */
