/**
 * @file polyroot.h
 *
 * @brief Quadratic formula.
 *
 * Quadratic Formula  is the solution of
 * the quadratic equation.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef POLYROOT_H
#define POLYROOT_H

#include <vector>

/**
 * @brief Quadratic formula.
 *
 * @param coef Coefficient vector.
 *
 * @return Roots of quadratic equation.
 *
 */
std::vector<double> polyroot(const std::vector<double>& coef);

#endif /* defined(POLYROOT_H) */
