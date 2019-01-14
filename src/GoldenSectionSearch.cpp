//
//  GoldenSectionSearch.cpp
//  GoldenSectionSearch
//
//

#include "GoldenSectionSearch.h"

Result GoldenSectionSearch(double a, double b, const double& tol,
                           const std::function<double(double)>& func) {
  assert(a < b);
  assert(tol > 0);
  Result result;
  const double inversePhi = (std::sqrt(5) - 1.0) / 2;   // 1 / phi
  const double inversePhi2 = (3.0 - std::sqrt(5)) / 2;  // 1 / phi^2
  double h = b - a;
  if (h <= tol) {
    result.a = a;
    result.b = b;
    return result;
  }
  int n = (int)std::ceil(std::log(tol / h) / std::log(inversePhi));
  double c = a + inversePhi2 * h;
  double d = a + inversePhi * h;
  double yc = func(c);
  double yd = func(d);
  for (int k = 0; k < n - 1; k++) {
    if (yc < yd) {
      b = d;
      d = c;
      yd = yc;
      h = inversePhi * h;
      c = a + inversePhi2 * h;
      yc = func(c);
    } else {
      a = c;
      c = d;
      yc = yd;
      h = inversePhi * h;
      d = a + inversePhi * h;
      yd = func(d);
    }
  }
  if (yc < yd) {
    result.a = a;
    result.b = d;
    return result;
  } else {
    result.a = c;
    result.b = b;
    return result;
  }
}
