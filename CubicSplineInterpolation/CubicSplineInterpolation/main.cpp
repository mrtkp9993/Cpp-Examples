//
//  main.cpp
//  CubicSplineInterpolation
//
//

#include "cubicSplineInterpolation.hpp"
#include <iostream>

int main(int argc, const char * argv[]) {
    Inputs inputs;
    inputs.n = 3;
    inputs.x = {0.0, 1.0, 2.0, 3.0};
    inputs.y = {1.0, 2.71, 7.39, 20.1};
    natCubicSplineInterpolation(inputs);
    return 0;
}
