//
//  GoldenSectionSearch.hpp
//  GoldenSectionSearch
//
//

#ifndef GoldenSectionSearch_hpp
#define GoldenSectionSearch_hpp

#include <stdio.h>
#include <cassert>
#include <cmath>
#include <functional>

struct Result {
    double a;
    double b;
};

Result GoldenSectionSearch(double a, double b, double tol, std::function<double(double)> func);

#endif /* GoldenSectionSearch_hpp */
