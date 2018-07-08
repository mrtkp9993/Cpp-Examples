//
//  finiteDifferences.cpp
//  finiteDifferences
//
//

#include "finiteDifferences.hpp"
#include <cmath>
#include <limits>
#include <vector>
#include "binom.hpp"

std::vector<double> forwardDifference(const std::vector<double>& arr,
                                      const int& order) {
  if (order < 0)
    throw std::invalid_argument("Order must be equal or greater than zero.");
  if (order > arr.size())
    throw std::invalid_argument(
        "Order must be equal or smaller than input array's size.");
  if (order == 0) return arr;
  int outArrSize = (int)arr.size() - order;
  std::vector<double> outArr(outArrSize, 0.0);
  for (int n = 0; n < outArrSize; n++) {
    for (int i = 0; i <= order; i++) {
      outArr[n] += std::pow(-1.0, i) * binomCoef(order, i) * arr[n + order - i];
    }
  }
  return outArr;
}
