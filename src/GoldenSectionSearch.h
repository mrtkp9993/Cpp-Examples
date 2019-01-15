//
//  GoldenSectionSearch.hpp
//  GoldenSectionSearch
//
//

#ifndef GOLDENSECTIONSEARCH_H
#define GOLDENSECTIONSEARCH_H

#include <stdio.h>
#include <cassert>
#include <cmath>
#include <functional>

struct Result {
  double a;
  double b;
};

Result GoldenSectionSearch(double a, double b, const double& tol,
                           const std::function<double(double)>& func);

#endif /* GOLDENSECTIONSEARCH_H */
