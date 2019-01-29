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

#ifndef SUBSETSUMPROBLEM_H
#define SUBSETSUMPROBLEM_H

#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

typedef std::vector<int> Set;
typedef std::vector<Set> PSet;

/**
 * Generate all subsets of given set.
 *
 * @param set A set.
 * @return Powerset of given set.
 */
PSet allSubsets(const Set& set);
/**
 * Solve subset-sum problem.
 *
 * @param set A set.
 * @param target Target sum.
 * @return A boolean that indicates there is a subset or not.
 */
bool subsetSum(const Set& set, const int& target);

#endif  // SUBSETSUMPROBLEM_H
