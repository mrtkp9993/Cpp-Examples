/**
 * @file goldenSectionSearch.h
 *
 * @brief Golden Section Search.
 *
 * The golden-section search is a technique for
 * finding the extremum (minimum or maximum) of a
 * strictly unimodal function by successively narrowing
 * the range of values inside which the extremum is
 * known to exist. The technique derives its name from
 * the fact that the algorithm maintains the function
 * values for triples of points whose distances form
 * a golden ratio.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef GOLDENSECTIONSEARCH_H
#define GOLDENSECTIONSEARCH_H

#include <stdio.h>
#include <cassert>
#include <cmath>
#include <functional>

/** @struct Result
 *  @brief The struct that stores result.
 *  @var Result::a
 *  Lower bound.
 *  @var Result::b
 *  Upper bound.
 */
struct Result {
  double a;
  double b;
};

/**
 * @brief Golden Section Search.
 *
 * @param a Lower bound.
 * @param b Upper bound.
 * @param tol Tolerance.
 * @param func The function.
 *
 * @return The interval with d-c<=tol.
 *
 */
Result GoldenSectionSearch(double a, double b, const double& tol,
                           const std::function<double(double)>& func);

#endif /* GOLDENSECTIONSEARCH_H */
