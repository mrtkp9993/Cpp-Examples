#ifndef METROPOLISHASTINGS_H
#define METROPOLISHASTINGS_H

#include <array>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

double runif(const double& a = 0, const double& b = 1);
double rnorm(const double& mean = 0, const double& sd = 1);
std::vector<double> generate(const std::function<double(double)>& target,
                             const unsigned int& count,
                             const unsigned int& burn_in_period);
double pchisq(const double& stat, const unsigned int& k);
bool jb_test(const std::vector<double>& x);
#endif  // METROPOLISHASTINGS_H
