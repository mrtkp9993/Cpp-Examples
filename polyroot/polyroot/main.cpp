//
//  main.cpp
//  polyroot
//
//

#include <iostream>
#include "polyroot.h"

int main(int argc, const char *argv[]) {
  // Coefficents are hard-coded.
  double a = 1;
  double b = -1;
  double c = -1;
  std::vector<double> coef = {a, b, c};
  std::vector<double> roots = polyroot(coef);
  const unsigned long rootSize = roots.size();
  for (int i = 0; i < rootSize; i++) {
    std::cout << roots.at(i) << "\n" << std::endl;
  }
  return EXIT_SUCCESS;
}
