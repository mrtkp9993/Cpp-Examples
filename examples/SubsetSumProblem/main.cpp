#include "../../src/subsetSumProblem.h"

int main() {
  Set set = {1, 2, 3, 6};
  const int sum = 9;
  if (subsetSum(set, sum)) {
    std::cout << "Subset was found for given sum." << std::endl;
  } else {
    std::cout << "Subset was not found for given sum." << std::endl;
  }
  return 0;
}