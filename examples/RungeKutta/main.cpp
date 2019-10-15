//
//  main.cpp
//  RungeKutta
//
//

#include <iostream>
#include "../../lib/numericCppExamplesLib/rungeKutta.h"

int main(int argc, const char* argv[]) {
  // define problem
  unsigned int N = 10;
  double a = 0.0;
  double b = 2.0;
  double init = 0.5;
  std::function<double(double, double)> func = [](double t, double y) {
    return y - std::pow(t, 2) + 1;
  };
  // solve
  double w = RK4(a, b, N, init, func);
  return 0;
}
