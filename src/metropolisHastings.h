#ifndef METROPOLISHASTINGS_H
#define METROPOLISHASTINGS_H

#include <ctime>
#include <functional>
#include <vector>
#include "../src/statistics.h"

std::vector<double> generate(const std::function<double(double)>& target,
                             const unsigned int& count,
                             const unsigned int& burn_in_period);

#endif  // METROPOLISHASTINGS_H
