#include <iomanip>
#include <iostream>
#include <numeric>
#include "../../lib/numericCppExamplesLib/brentSalaminFormula.h"

int main() {
  auto appr_pi = calc_pi<long double>(15);
  std::cout << std::setprecision(17);
  std::cout << M_PI << std::endl;
  std::cout << appr_pi << std::endl;
  return 0;
}