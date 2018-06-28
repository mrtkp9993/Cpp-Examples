//
//  NumericalIntegration.hpp
//
//
//

#ifndef NumericalIntegration_hpp
#define NumericalIntegration_hpp

#include <stdio.h>
#include <functional>
#include <iostream>

double compositeSimpsons(double a, double b, unsigned long n,
                         std::function<double(double)> func);

double doubleIntegral(double a, double b, unsigned long m, unsigned long n,
                      std::function<double(double)> c,
                      std::function<double(double)> d,
                      std::function<double(double, double)> func);

#endif /* NumericalIntegration_hpp */
