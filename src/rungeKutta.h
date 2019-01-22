/**
 * @file rungeKutta.h
 *
 * @brief Runge-Kutta Order Four.
 *
 * Runge-Kutta methods are a family of implicit
 * and explicit iterative methods, which include
 * the well-known routine called the Euler Method,
 * used in temporal discretization for the
 * approximate solutions of ordinary differential equations.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef RUNGEKUTTA_H
#define RUNGEKUTTA_H

#include <stdio.h>
#include <cmath>
#include <functional>
#include <iostream>

/**
 * @brief Runge-Kutta Order Four.
 *
 * @param a Endpoint.
 * @param b Endpoint.
 * @param N Iteration count.
 * @param init Initial condition.
 * @param func A function.
 *
 * @return Approximation to exact solution.
 *
 */
double RK4(const double& a, const double& b, const unsigned int& N,
           const double& init,
           const std::function<double(double, double)>& func);

#endif /* RUNGEKUTTA_H */
