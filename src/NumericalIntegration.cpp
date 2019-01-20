//
//
//  Algorithm 4.1 (Numerical Analysis, Ninth Edition, Burden, Faires)
//  Composite Simpson's Rule

#include "numericalIntegration.h"

double compositeSimpsons(const double& a, const double& b,
                         const unsigned long& n,
                         const std::function<double(double)>& func) {
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
    double X = a + i * h;
    // STEP 5
    if (i % 2 == 0) {
      XI2 = XI2 + func(X);
    } else {
      XI1 = XI1 + func(X);
    }
  }
  XI = h * (XI0 + 2 * XI2 + 4 * XI1) / 3;
  std::cout << "Approximation to integral: " << XI << std::endl;
  return XI;
}

double doubleIntegral(const double& a, const double& b, const unsigned long& m,
                      const unsigned long& n,
                      const std::function<double(double)>& c,
                      const std::function<double(double)>& d,
                      const std::function<double(double, double)>& func) {
  assert(m % 2 == 0);
  assert(n % 2 == 0);
  double J = 0.0;
  // STEP 1
  double h = (b - a) / n;
  double J1 = 0.0;
  double J2 = 0.0;
  double J3 = 0.0;
  // STEP 2
  for (int i = 0; i <= n; i++) {
    // STEP 3
    double x = a + i * h;
    double cx = c(x);
    double dx = d(x);
    double HX = (dx - cx) / m;
    double K1 = func(x, cx) + func(x, dx);
    double K2 = 0.0;
    double K3 = 0.0;
    // STEP 4
    for (int j = 1; j <= m - 1; j++) {
      // STEP 5
      double y = cx + j * HX;
      double Q = func(x, y);
      // STEP 6
      if (j % 2 == 0) {
        K2 += Q;
      } else {
        K3 += Q;
      }
    }
    // STEP 7
    double L = (K1 + 2 * K2 + 4 * K3) * HX / 3;
    // STEP 8
    if (i == 0 || i == n) {
      J1 += L;
    } else if (i % 2 == 0) {
      J2 += L;
    } else {
      J3 += L;
    }
  }
  // STEP 9
  J = h * (J1 + 2 * J2 + 4 * J3) / 3;
  std::cout << "Approximation to integral: " << J << std::endl;
  return J;
}

double monteCarloIntegration(const double& a, const double& b,
                             const unsigned long& n,
                             std::function<double(double)>& func) {
  std::vector<double> X(n, 0);
  for (unsigned int i = 0; i < n; i++) {
    X[i] = runif(a, b);
  }

  double sum = 0;
  for (auto xi : X) {
    sum += func(xi);
  }

  auto result = (b - a) / n * sum;

  std::cout << "Approximation to integral: " << result << std::endl;
  return result;
}