//
//  main.cpp
//  finiteDifferences
//
//

#include <iostream>
#include <vector>
#include "finiteDifferences.hpp"

int main(int argc, const char* argv[]) {
  std::vector<double> arr = {90.0, 47.0, 58.0, 29.0, 22.0,
                             32.0, 55.0, 5.0,  55.0, 73.0};
  std::vector<double> outArr = forwardDifference(arr, 1);
  for (int i = 0; i < outArr.size(); i++) {
    std::cout << outArr.at(i) << std::endl;
  }
  return 0;
}
