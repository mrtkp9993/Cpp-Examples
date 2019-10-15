#include <iomanip>
#include <iostream>
#include "../../lib/numericCppExamplesLib/bbpTypeFormula.h"

int main() {
  std::cout << "BBP Type formula implementation" << std::endl;
  std::cout << "Pi approximation: " << std::setprecision(10)
            << P(1, 16, 8, std::vector<int>{4, 0, 0, -2, -1, -1, 0, 0}, 10)
            << std::endl;
  std::cout << "ln(3) approximation:" << std::setprecision(10)
            << P(1, 4, 2, std::vector<int>{1, 0}, 10) << std::endl;
  return 0;
}