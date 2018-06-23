//
//  main.cpp
//  CompositeSimpsonsRule
//
//

#include <cmath>
#include <iostream>
#include "CompositeSimpsonsRule.hpp"

int main(int argc, const char* argv[]) {
  double a = 0.0;
  double b = M_PI;
  unsigned long n = 6;
  std::function<double(double)> func = [](double x) {
    return std::pow(x, 2) * std::cos(x);
  };
  compositeSimpsons(a, b, n, func);
  return 0;
}
