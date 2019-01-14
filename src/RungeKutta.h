//
//  RungeKutta.hpp
//  RungeKutta
//
//
//  Algorithm 5.2 (Numerical Analysis, Ninth Edition, Burden, Faires)
//  Runge-Kutta Order Four

#ifndef RungeKutta_hpp
#define RungeKutta_hpp

#include <stdio.h>
#include <cmath>
#include <functional>
#include <iostream>

double RK4(const double& a, const double& b, const unsigned int& N,
           const double& init,
           const std::function<double(double, double)>& func);

#endif /* RungeKutta_hpp */
