//
//  finiteDifferences.hpp
//  finiteDifferences
//
//

#ifndef FINITEDIFFRENCES_H
#define FINITEDIFFRENCES_H

#include <cmath>
#include <limits>
#include <vector>
#include <stdexcept>

std::vector<double> forwardDifference(const std::vector<double>& arr,
                                      const int& order);

#endif /* FINITEDIFFRENCES_H */
