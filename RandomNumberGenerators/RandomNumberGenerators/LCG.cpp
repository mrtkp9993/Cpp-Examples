//
//  LCG.cpp
//  RandomNumberGenerators
//
//

#include "LCG.hpp"

std::vector<int> lcg(int seed, int mod, int mult, int incr, int count) {
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
