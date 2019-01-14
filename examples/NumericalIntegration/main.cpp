//
//  main.cpp
//  Numerical Integration
//
//

#include <cmath>
#include <iostream>
#include "../../src/NumericalIntegration.h"

int main(int argc, const char* argv[]) {
  // Composite Simpson
  double a = 0.0;
  double b = M_PI;
  unsigned long n = 6;
  std::function<double(double)> func = [](double x) {
    return std::pow(x, 2) * std::cos(x);
  };
  compositeSimpsons(a, b, n, func);
  // Double Simpson
  unsigned long m1 = 6;
  unsigned long n1 = 6;
  double a1 = 0.0;
  double b1 = M_PI_4;
  std::function<double(double)> c = [](double x) { return std::sin(x); };
  std::function<double(double)> d = [](double x) { return std::cos(x); };
  std::function<double(double, double)> func1 = [](double x, double y) {
    return 2 * y * std::sin(x) + std::pow(std::cos(x), 2);
  };
  doubleIntegral(a1, b1, m1, n1, c, d, func1);
  return 0;
}
