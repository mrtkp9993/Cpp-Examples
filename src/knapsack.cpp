/**
 * @file knapsack.h
 *
 * @brief Solve Knapsack problem.
 *
 * The knapsack problem or rucksack problem is a problem in combinatorial
 * optimization: Given a set of items, each with a weight and a value, determine
 * the number of each item to include in a collection so that the total weight
 * is less than or equal to a given limit and the total value is as large as
 * possible. It derives its name from the problem faced by someone who is
 * constrained by a fixed-size knapsack and must fill it with the most valuable
 * items.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 27/Jan/2019.
 *
 */

#include "knapsack.h"

/**
 * @brief Maximum of two unsigned integers.
 *
 * @param a An integer.
 * @param b An integer.
 *
 * @return Maximum of a and b.
 */
unsigned int max(const unsigned int& a, const unsigned int& b) {
  return (a > b) ? a : b;
}

/**
 * @brief Helper function for printing matrices.
 * @param M A matrix
 */
void printMat(const mat& M) {
  for (auto r : M) {
    for (auto c : r) {
      std::cout << c << "\t";
    }
    std::cout << "\n" << std::endl;
  }
}
/**
 * @brief Solve 0-1 Knapsack problem.
 *
 * @param v Value vector.
 * @param w Weight vector.
 * @param n Item count.
 * @param W Maximum allowed weight.
 * @param print A boolean. If true, function prints the matrix.
 *
 * @return Maximum value.
 */
double Knapsack01(const vec& v, const vec& w, const unsigned int& n,
                  const unsigned int& W, const bool& print) {
  mat M(n + 1, vec(W + 1, 0));

  for (unsigned int i = 1; i <= n; i++) {
    for (unsigned int j = 1; j <= W; j++) {
      if (w[i - 1] <= j)
        M[i][j] = max(v[i - 1] + M[i - 1][j - w[i - 1]], M[i - 1][j]);
      else
        M[i][j] = M[i - 1][j];
    }
  }
  uint ww = W;
  uint res = M[n][W];
  // Backtracking for solution set
  for (uint i = n; i > 0 && res > 0; i--) {
    if (res == M[i - 1][ww])
      continue;
    else {
      std::cout << "Take " << i << "th item from the list" << std::endl;
      res -= v[i - 1];
      ww -= w[i - 1];
    }
  }

  // print
  if (print) printMat(M);

  return M[n][W];
}