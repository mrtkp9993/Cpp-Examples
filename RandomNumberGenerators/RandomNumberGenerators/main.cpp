//
//  main.cpp
//  RandomNumberGenerators
//
//

#include <iostream>
#include "LCG.hpp"

int main(int argc, const char * argv[]) {
    // Linear congruential generator
    std::vector<int> rndInt = lcg(7, 10, 7, 7, 12);
    for (int i = 0; i < rndInt.size(); i++) {
        std::cout << rndInt[i] << std::endl;
    }
    return 0;
}
