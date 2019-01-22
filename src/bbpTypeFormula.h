/**
 * @file bbpTypeFormula.h
 *
 * @brief BPP Type formula calculation.
 *
 * The Bailey–Borwein–Plouffe formula (BBP formula) is a
 * spigot algorithm which is an algorithm for computing
 * the value of a mathematical constant such as π or e
 * which generates output digits in some base
 * (usually 2 or a power of 2) from left to right,
 * with limited intermediate storage. The name comes from
 * the sense of the word "spigot" for a tap or valve
 * controlling the flow of a liquid.
 *
 * Formula was taken from:
 * https://bbp.carma.newcastle.edu.au/
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef BBPTYPEFORMULA_H
#define BBPTYPEFORMULA_H

#include <cassert>
#include <cmath>
#include <vector>

/**
 * @brief BPP Type formula calculation.
 *
 * @param s An integer.
 * @param b An integer.
 * @param n An integer.
 * @param A A sequence of integers.
 * @param n_iter Iteration count.
 *
 * @return Approximation of a number.
 *
 */
long double P(const int &s, const int &b, const int &n,
              const std::vector<int> &A, const int &n_iter);

#endif  // BBPTYPEFORMULA_H
