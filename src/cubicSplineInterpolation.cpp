//
//  cubicSplineInterpolation.cpp
//
//  Algorithm 3.4 (Numerical Analysis, Ninth Edition, Burden, Faires)
//  Natural Cubic Spline
//  To construct the cubic spline interpolant S for the function f,
//  defined at the numbers x0 < x1 < ... < xn, satisfying
//  S''(x0) = S''(xn) = 0
//

#include "cubicSplineInterpolation.h"
#include <iostream>
#include <vector>

Solution natCubicSplineInterpolation(const Inputs& inputs) {
  unsigned long n = inputs.n;
  std::vector<double> x = inputs.x;
  std::vector<double> y = inputs.y;
  Solution sol;
  sol.a = y;
  sol.b.resize(n);
  sol.c.resize(n);
  sol.d.resize(n);
  // STEP 1
  std::vector<double> h(n, 0.0);
  for (int i = 0; i < n; i++) {
    h[i] = x[i + 1] - x[i];
  }
  // STEP 2
  std::vector<double> alpha(n - 1, 0.0);
  for (int i = 1; i <= n - 1; i++) {
    alpha[i] =
        (3 / h[i]) * (y[i + 1] - y[i]) - (3 / h[i - 1]) * (y[i] - y[i - 1]);
  }
  // STEP 3
  std::vector<double> l(n, 0.0);
  std::vector<double> mu(n, 0.0);
  std::vector<double> z(n, 0.0);
  l[0] = 1;
  mu[0] = 0;
  z[0] = 0;
  // STEP 4
  for (int i = 1; i <= n - 1; i++) {
    l[i] = 2 * (x[i + 1] - x[i - 1]) - h[i - 1] * mu[i - 1];
    mu[i] = h[i] / l[i];
    z[i] = (alpha[i] - h[i - 1] * z[i - 1]) / l[i];
  }
  // STEP 5
  l[n] = 1;
  z[n] = 0;
  sol.c[n] = 0;
  // STEP 6
  for (int j = n - 1; j >= 0; j--) {
    sol.c[j] = z[j] - mu[j] * sol.c[j + 1];
    sol.b[j] =
        (y[j + 1] - y[j]) / h[j] - h[j] * (sol.c[j + 1] + 2 * sol.c[j]) / 3;
    sol.d[j] = (sol.c[j + 1] - sol.c[j]) / (3 * h[j]);
  }
  // STEP 7
  std::cout << "Coefficents for S(x) = S_j(x) = a_j + b_j(x-x_j) + "
               "c_j(x-x_j)^2 + d_j(x-x_j)^3"
            << std::endl;
  for (int j = 0; j <= n - 1; j++) {
    std::cout << "a" << j << ": " << sol.a.at(j) << std::endl;
    std::cout << "b" << j << ": " << sol.b.at(j) << std::endl;
    std::cout << "c" << j << ": " << sol.c.at(j) << std::endl;
    std::cout << "d" << j << ": " << sol.d.at(j) << std::endl;
  }
  return sol;
}
