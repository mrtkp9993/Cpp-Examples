//
//  CompositeSimpsonsRule.cpp
//  CompositeSimpsonsRule
//
//
//  Algorithm 4.1 (Numerical Analysis, Ninth Edition, Burden, Faires)
//  Composite Simpson's Rule

#include "CompositeSimpsonsRule.hpp"

double compositeSimpsons(double a, double b, unsigned long n, std::function<double(double)> func) {
    double X = 0.0;
    double XI = 0.0;
    // STEP 1
    double h = (b - a) / n;
    // STEP 2
    double XI0 = func(a) + func(b);
    double XI1 = 0.0;
    double XI2 = 0.0;
    // STEP 3
    for (int i = 1; i <= n - 1; i++) {
        // STEP 4
        X = a + i * h;
        // STEP 5
        if (i % 2 == 0) {
            XI2 = XI2 + func(X);
        } else {
            XI1 = XI1 + func(X);
        }
    }
    XI = h * (XI0 + 2 * XI2 + 4 * XI1) / 3;
    std::cout << "Approximation to integral of f from a to b: " << XI << std::endl;
    return XI;
}
