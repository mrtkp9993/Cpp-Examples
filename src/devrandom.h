//
//  devrandom.hpp
//  RandomNumberGenerators
//
//

#ifndef DEVRANDOM_H
#define DEVRANDOM_H

#include <stdio.h>
#include <fstream>
#include <iostream>

template <typename T>
T devrandom() {
  T random_value{};
  size_t size = sizeof(random_value);
  std::ifstream random("/dev/random", std::ios::in | std::ios::binary);
  if (random) {
    random.read(reinterpret_cast<char*>(&random_value), size);
    if (random) {
      std::cout << random_value << std::endl;
    } else {
      std::cerr << "Failed to read from /dev/random" << std::endl;
    }
    random.close();
  } else {
    std::cerr << "Failed to read from /dev/random" << std::endl;
  }
  return random_value;
}

#endif /* DEVRANDOM_H */
