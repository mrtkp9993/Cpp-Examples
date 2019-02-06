/**
 * @file numericalIntegration.h
 *
 * @brief Numerical integration methods.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef NUMERICALINTEGRATION_H
#define NUMERICALINTEGRATION_H

#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>
#include <numeric>
#include "statistics.h"

/**
 * @brief Composite Simpson’s Integration.
 *
 * Composite Simpson is a method for the
 * numerical approximation of definite integrals.
 *
 * @param a Endpoint.
 * @param b Endpoint.
 * @param n Iteration count.
 * @param func The function that will be integrated.
 *
 * @return Approximation to integral.
 *
 */
double compositeSimpsons(const double& a, const double& b,
                         const unsigned long& n,
                         const std::function<double(double)>& func);

/**
 * @brief Double Simpson’s Integration.
 *
 * Double Simpson is a method for the
 * numerical approximation of double integrals.
 *
 * @param a Endpoint.
 * @param b Endpoint.
 * @param m Iteration count.
 * @param n Iteration count.
 * @param c A function.
 * @param d A function.
 * @param func The function that will be integrated.
 *
 * @return Approximation to integral.
 *
 */
double doubleIntegral(const double& a, const double& b, const unsigned long& m,
                      const unsigned long& n,
                      const std::function<double(double)>& c,
                      const std::function<double(double)>& d,
                      const std::function<double(double, double)>& func);

/**
 * @brief Monte-Carlo Integration.
 *
 * Monte-Carlo Integration is a technique for numerical
 * integration using random numbers. It is a particular
 * Monte Carlo method that numerically computes a definite
 * integral.
 *
 * @param a Endpoint.
 * @param b Endpoint.
 * @param n Iteration count.
 * @param func The function that will be integrated.
 *
 * @return Approximation to integral.
 *
 */
long double monteCarloIntegration(
    const long double& a, const long double& b, const unsigned long& n,
    std::function<long double(long double)>& func);

#endif /* NUMERICALINTEGRATION_H */
