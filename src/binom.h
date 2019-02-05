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

#include <stdio.h>

/**
 * @brief Calculate binomial coefficient.
 *
 * @param n An integer.
 * @param k An integer.
 *
 * @return Binomial coefficient.
 *
 */
unsigned long binomCoef(const unsigned long &n, const unsigned long &k);

#endif /* BINOM_H */
