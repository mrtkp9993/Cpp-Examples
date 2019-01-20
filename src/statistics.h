#ifndef STATISTICS_H
#define STATISTICS_H

#include <cmath>
#include <numeric>
#include <vector>

double runif(const double& a = 0, const double& b = 1);
double rnorm(const double& mean = 0, const double& sd = 1);
double pchisq(const double& stat, const unsigned int& k);
bool jb_test(const std::vector<double>& x);

#endif  // STATISTICS_H
