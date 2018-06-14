//
//  LCG.hpp
//  RandomNumberGenerators
//

#ifndef LCG_hpp
#define LCG_hpp

#include <stdio.h>
#include <cassert>
#include <cmath>
#include <vector>

std::vector<int> lcg(int seed, int mod, int mult, int incr, int count);

#endif /* LCG_hpp */
