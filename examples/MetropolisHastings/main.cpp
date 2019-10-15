#include <iostream>
#include "../../lib/numericCppExamplesLib/metropolisHastings.h"

double target(const double& x) { return x < 0 ? 0 : std::exp(-x); }

int main() {
  std::vector<long double> nums = generate<long double>(target, 10000, 2500);
  for (auto num : nums) {
    std::cout << num << std::endl;
  }
  return 0;
}