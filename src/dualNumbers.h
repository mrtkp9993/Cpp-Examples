/**
 * @file dualNumbers.h
 *
 * @brief Implementation of dual numbers.
 *
 * In linear algebra, the dual numbers extend the real numbers by adjoining one
 * new element ε with the property ε^2 = 0 (ε is nilpotent).
 *
 * @author Murat Koptur <mkoptur3@gmail.com>
 *
 * Last updated: 3/Feb/2019.
 *
 */

#ifndef DUALNUMBERS_H
#define DUALNUMBERS_H

#include <cmath>
#include <iostream>

struct Dual {
  long double real;
  long double dual;

  Dual(const long double& a) {
    this->real = a;
    this->dual = 0;
  }
  Dual(const long double& a, const long double& b) {
    this->real = a;
    this->dual = b;
  }

  friend Dual operator+(const Dual& u, const Dual& v);
  friend Dual operator-(const Dual& u, const Dual& v);
  friend Dual operator*(const Dual& u, const Dual& v);
  friend Dual operator/(const Dual& u, const Dual& v);

  friend std::ostream& operator<<(std::ostream& os, const Dual& d);

  friend Dual pow(const Dual& d, const long double& p);
  friend Dual root(const Dual& d, const long double& p);
  friend Dual exp(const Dual& d);
  friend Dual log(const Dual& d);
  friend Dual sin(const Dual& d);
  friend Dual cos(const Dual& d);
  friend Dual tan(const Dual& d);
  friend Dual asin(const Dual& d);
  friend Dual acos(const Dual& d);
  friend Dual atan(const Dual& d);
  friend Dual sinh(const Dual& d);
  friend Dual cosh(const Dual& d);
  friend Dual tanh(const Dual& d);
};

#endif  // DUALNUMBERS_H
