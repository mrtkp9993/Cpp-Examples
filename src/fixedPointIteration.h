//
//  FixedPointIteration.hpp
//  FixedPointIteration
//
//
//  Algorithm 2.2 (Numerical Analysis, Ninth Edition, Burden, Faires)
//  Fixed-Point Iteration

#ifndef FIXEDPOINTITERATION_H
#define FIXEDPOINTITERATION_H

#include <stdio.h>
#include <cmath>
#include <functional>
#include <iostream>

double fixedPointIter(double p0, const double& tol, const unsigned long& N0,
                      const std::function<double(double)>& g);

#endif /* FIXEDPOINTITERATION_H */
