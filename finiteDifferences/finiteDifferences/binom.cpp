//
//  binom.cpp
//  finiteDifferences
//
//

#include "binom.hpp"
#include <cmath>

double binomCoef(const unsigned long& n, const unsigned long& k) {
  double nCk =
      std::tgamma(n + 1) / (std::tgamma(n - k + 1) * std::tgamma(k + 1));
  return nCk;
}
