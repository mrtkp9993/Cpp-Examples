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

/** A type for complex numbers. */
typedef std::complex<double> Complex;
/** A type for array of complex numbers. */
typedef std::vector<Complex> CVec;

/**
 * Calculate DFT for given input.
 *
 * @param input Vector of complex numbers.
 *
 * @return DFT.
 */
CVec dft(const CVec& input);
/**
 * Calculate IDFT for given input.
 *
 * @param input Vector of complex numbers.
 *
 * @return IDFT.
 */
CVec idft(const CVec& input);

#endif  // DISCRETEFOURIERTRANSFORM_H
