/**
 * @file subsetSumProblem.h
 *
 * @brief Solve Subset-Sum Problem.
 *
 * In computer science, the subset sum problem is an important decision problem
 * in complexity theory and cryptography. There are several equivalent
 * formulations of the problem. One of them is: given a set (or multiset) of
 * integers, is there a non-empty subset whose sum is zero?
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 29/Jan/2019.
 *
 */
#include "subsetSumProblem.h"

/**
 * Generate all subsets of given set.
 *
 * @param set A set.
 * @return Powerset of given set.
 */
PSet allSubsets(const Set& set) {
  PSet powerset = {};

  for (int counter = 0; counter < std::pow(2, set.size()); counter++) {
    Set temp;
    for (int j = 0; j < set.size(); j++)
      if (counter & (1 << j)) temp.push_back(set[j]);
    powerset.push_back(temp);
  }

  return powerset;
}

/**
 * Solve subset-sum problem.
 *
 * @param set A set.
 * @param target Target sum.
 * @return A boolean that indicates there is a subset or not.
 */
bool subsetSum(const Set& set, const int& target) {
  PSet powerset = allSubsets(set);

  for (auto set : powerset) {
    auto subset_sum = std::accumulate(set.begin(), set.end(), 0);
    if (subset_sum == target) {
      return true;
    }
  }

  return false;
}