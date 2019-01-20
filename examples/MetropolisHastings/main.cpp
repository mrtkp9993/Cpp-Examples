#include <iostream>
#include "../../src/metropolisHastings.h"

double target(const double& x) { return x < 0 ? 0 : std::exp(-x); }

int main() {
  std::vector<double> nums = generate(target, 10000, 2500);
  for (auto num : nums) {
    std::cout << num << std::endl;
  }
  return 0;
}