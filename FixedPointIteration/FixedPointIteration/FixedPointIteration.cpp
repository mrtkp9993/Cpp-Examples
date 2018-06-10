//
//  FixedPointIteration.cpp
//  FixedPointIteration
//
//
//  Algorithm 2.2 (Numerical Analysis, Ninth Edition, Burden, Faires)
//  Fixed-Point Iteration
//  To ind a solution to p = g(p) given an initial approximation p_0.

#include "FixedPointIteration.hpp"

double fixedPointIter(double p0, double tol, unsigned long N0, std::function<double(double)> g) {
    unsigned long i = 1;
    bool rootFound = false;
    while (i <= N0) {
        double p = g(p0);
        if (std::abs(p - p0) < tol) {
            std::cout << "Root found after " << i << " iterations: " << p << std::endl;
            rootFound = true;
            return p;
        }
        i += 1;
        p0 = p;
    }
    if (rootFound != true){
        std::cout << "The method failed after " << N0 << " iterations" << std::endl;
    }
    return -1;
}
