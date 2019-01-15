//
//  cubicSplineInterpolation.hpp
//  CubicSplineInterpolation
//
//

#ifndef CUBICSPLINEINTERPOLATION_H
#define CUBICSPLINEINTERPOLATION_H

#include <stdio.h>
#include <vector>

struct Inputs {
  unsigned long n;
  std::vector<double> x;
  std::vector<double> y;
};

struct Solution {
  std::vector<double> a{0.0};
  std::vector<double> b{0.0};
  std::vector<double> c{0.0};
  std::vector<double> d{0.0};
};

Solution natCubicSplineInterpolation(const Inputs& inputs);

#endif /* CUBICSPLINEINTERPOLATION_H */
