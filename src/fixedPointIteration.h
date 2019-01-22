/**
 * @file fixedPointIteration.h
 *
 * @brief Fixed point iteration.
 *
 * Fixed Point Iteration is a method of computing
 * fixed points of iterated functions. We can write
 * an equation f(x)=0 in x=g(x) form and we can
 * find this equation’s fixed point and solve first
 * equation.
 *
 * Algorithm 2.2 (Numerical Analysis, Ninth Edition, Burden, Faires)

 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef FIXEDPOINTITERATION_H
#define FIXEDPOINTITERATION_H

#include <stdio.h>
#include <cmath>
#include <functional>
#include <iostream>


/**
 * @brief Find a solution to p = g(p) given an initial approximation p0.
 *
 * @param p0 Initial approximation.
 * @param tol Tolerance.
 * @param N0 Maximum number of iterations.
 * @param g The function.
 *
 * @return Approximate solution p or message of failure..
 *
 */
double fixedPointIter(double p0, const double& tol, const unsigned long& N0,
                      const std::function<double(double)>& g);

#endif /* FIXEDPOINTITERATION_H */
