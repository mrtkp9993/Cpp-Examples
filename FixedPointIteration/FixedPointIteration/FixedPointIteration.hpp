//
//  FixedPointIteration.hpp
//  FixedPointIteration
//
//
//  Algorithm 2.2 (Numerical Analysis, Ninth Edition, Burden, Faires)
//  Fixed-Point Iteration

#ifndef FixedPointIteration_hpp
#define FixedPointIteration_hpp

#include <stdio.h>
#include <cmath>
#include <functional>
#include <iostream>

double fixedPointIter(double p0, double tol, unsigned long N0,
                      std::function<double(double)> g);

#endif /* FixedPointIteration_hpp */
