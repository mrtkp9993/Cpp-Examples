//
//  LCG.cpp
//  RandomNumberGenerators
//
//

#include "lcg.h"

std::vector<int> lcg(const int& seed, const int& mod, const int& mult,
                     const int& incr, const int& count) {
  assert(mod > 0);
  assert(0 < mult < mod);
  assert(0 <= incr < mod);
  assert(0 <= seed < mod);
  std::vector<int> randInts(count);
  randInts[0] = seed;
  for (int n = 1; n < count; n++) {
    randInts[n] = (mult * randInts[n - 1] + incr) % mod;
  }
  return randInts;
}
