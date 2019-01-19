//
//  NumericalIntegration.hpp
//
//
//

#ifndef NUMERICALINTEGRATION_H
#define NUMERICALINTEGRATION_H

#include <cassert>
#include <cstdio>
#include <functional>
#include <iostream>

double compositeSimpsons(const double& a, const double& b,
                         const unsigned long& n,
                         const std::function<double(double)>& func);

double doubleIntegral(const double& a, const double& b, const unsigned long& m,
                      const unsigned long& n,
                      const std::function<double(double)>& c,
                      const std::function<double(double)>& d,
                      const std::function<double(double, double)>& func);

#endif /* NUMERICALINTEGRATION_H */
