/**
 * @file devrandom.h
 *
 * @brief Generate random numbers/strings from /dev/random.
 *
 * /dev/random is special file that serve as
 * pseudorandom number generator. They allow access to
 * environmental noise collected from device drivers
 * and other sources.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 22/Jan/2019.
 *
 */

#ifndef DEVRANDOM_H
#define DEVRANDOM_H

#include <stdio.h>
#include <fstream>
#include <iostream>

namespace RandomNumberGenerators {
/**
 * @brief A function template which takes a type as argument
 * and returns an random element of that type.
 *
 * @param T A type.
 *
 * @return Random element.
 *
 */
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
}  // namespace RandomNumberGenerators
#endif /* DEVRANDOM_H */
