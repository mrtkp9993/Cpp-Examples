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

std::vector<int> lcg(const int& seed, const int& mod, const int& mult,
                     const int& incr, const int& count);

#endif /* LCG_hpp */
