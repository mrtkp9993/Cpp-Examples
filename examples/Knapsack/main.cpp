#include "../../src/knapsack.h"

int main() {
  std::cout << "========problem1" << std::endl;
  uint n1 = 5;
  uint W1 = 11;
  vec v1({1, 6, 18, 22, 28});
  vec w1({1, 2, 5, 6, 7});
  std::cout << Knapsack01(v1, w1, n1, W1) << std::endl;

  std::cout << "========problem2" << std::endl;
  uint n2 = 3;
  uint W2 = 50;
  vec v2({60, 100, 120});
  vec w2({10, 20, 30});
  std::cout << Knapsack01(v2, w2, n2, W2) << std::endl;

  std::cout << "========problem3" << std::endl;
  uint n3 = 4;
  uint W3 = 7;
  vec v3({1, 4, 5, 7});
  vec w3({1, 3, 4, 5});
  std::cout << Knapsack01(v3, w3, n3, W3, true) << std::endl;

  return 0;
}