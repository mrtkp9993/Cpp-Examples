#include "../../lib/numericCppExamplesLib/discreteFourierTransform.h"

int main() {
  CVec<> x({1, 2, 3, 4, 5, 6, 7, 8});
  auto y = dft(x);
  std::cout << std::showpos;
  for (auto yi : y) {
    std::cout << yi.real() << yi.imag() << "i" << std::endl;
  }
  auto x_ = idft(y);
  for (auto xi : x_) {
    std::cout << xi.real() << xi.imag() << "i" << std::endl;
  }
  return 0;
}