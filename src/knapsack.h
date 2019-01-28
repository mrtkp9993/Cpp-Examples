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

#ifndef KNAPSACK_H
#define KNAPSACK_H

#include <cmath>
#include <iostream>
#include <vector>

/** A type for columns of matrix. */
typedef std::vector<unsigned int> vec;
/** A type for store matrix. */
typedef std::vector<std::vector<unsigned int>> mat;

/**
 * @brief Maximum of two unsigned integers.
 *
 * @param a An integer.
 * @param b An integer.
 *
 * @return Maximum of a and b.
 */
unsigned int max(const unsigned int& a, const unsigned int& b);
/**
 * @brief Helper function for printing matrices.
 * @param M A matrix
 */
void printMat(const mat& M);
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
                  const unsigned int& W, const bool& print = false);

#endif  // KNAPSACK_H
