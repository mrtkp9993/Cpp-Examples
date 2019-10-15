#include "../../lib/numericCppExamplesLib/lagrangeInterpolation.h"

int main() {
  Data<long double> data1{std::vector<long double>{1, 2, 3},
                          std::vector<long double>{1, 4, 9}};
  auto poly1 = lagrangePoly(data1);
  std::cout << poly1(2) << std::endl;

  Data<long double> data2{std::vector<long double>{-1, 0, 1, 2},
                          std::vector<long double>{3, -4, 5, -6}};
  auto poly2 = lagrangePoly(data2);
  std::cout << poly2(0.5) << std::endl;

  return 0;
}