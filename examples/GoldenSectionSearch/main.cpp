//
//  main.cpp
//  GoldenSectionSearch
//
//

#include <iomanip>
#include <iostream>
#include "../../src/goldenSectionSearch.h"

int main(int argc, const char* argv[]) {
  // define problem
  std::function<double(double)> func = [](double x) {
    return std::pow(x - 2, 2);
  };
  double a = 1;
  double b = 5;
  double tol = 1e-5;
  // solve
  Result res = GoldenSectionSearch(a, b, tol, func);
  std::cout << std::setprecision(15) << "a = " << res.a << " , b = " << res.b
            << std::endl;
  return 0;
}
