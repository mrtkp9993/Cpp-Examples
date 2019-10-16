/**
 * @file discreteFourierTransform.h
 *
 * @brief Functions for DFT and IDFT.
 *
 * In mathematics, the discrete Fourier transform (DFT) converts a finite
 * sequence of equally-spaced samples of a function into a same-length sequence
 * of equally-spaced samples of the discrete-time Fourier transform (DTFT),
 * which is a complex-valued function of frequency.
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 2/Feb/2019.
 *
 */

#ifndef DISCRETEFOURIERTRANSFORM_H
#define DISCRETEFOURIERTRANSFORM_H

#include <cmath>
#include <complex>
#include <iostream>
#include <vector>

namespace IntegralTransforms {
/** A type for complex numbers. */
template <typename T = long double>
using Complex = std::complex<T>;
/** A type for array of complex numbers. */
template <typename T = long double>
using CVec = std::vector<std::complex<T>>;

/**
 * Calculate DFT for given input.
 *
 * @param input Vector of complex numbers.
 *
 * @return DFT.
 */
CVec<> dft(const CVec<>& input) {
  const auto N = input.size();
  CVec<> result(N, (0.0, 0.0));
  for (auto n = 0; n < N; n++) {
    auto real = 0.0;
    auto img = 0.0;
    for (auto k = 0; k < N; k++) {
      auto angle = 2 * M_PI * k * n / N;
      real +=
          input[k].real() * std::cos(angle) + input[k].imag() * std::sin(angle);
      img +=
          input[k].imag() * std::cos(angle) - input[k].real() * std::sin(angle);
    }
    result[n] = Complex<>(real, img);
  }
  return result;
}

/**
 * Calculate IDFT for given input.
 *
 * @param input Vector of complex numbers.
 *
 * @return IDFT.
 */
CVec<> idft(const CVec<>& input) {
  const auto N = input.size();
  CVec<> result(N, (0.0, 0.0));
  for (auto n = 0; n < N; n++) {
    auto real = 0.0;
    auto img = 0.0;
    for (auto k = 0; k < N; k++) {
      auto angle = 2 * M_PI * k * n / N;
      real +=
          input[k].real() * std::cos(angle) - input[k].imag() * std::sin(angle);
      img +=
          input[k].imag() * std::cos(angle) + input[k].real() * std::sin(angle);
    }
    result[n] = Complex<>(real / N, img / N);
  }
  return result;
}
}  // namespace IntegralTransforms
#endif  // DISCRETEFOURIERTRANSFORM_H
