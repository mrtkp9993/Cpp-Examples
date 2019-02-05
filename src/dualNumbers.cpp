/**
 * @file dualNumbers.cpp
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

#include "dualNumbers.h"

Dual operator+(const Dual& u, const Dual& v) {
  return Dual(u.real + v.real, u.dual + v.dual);
}

Dual operator-(const Dual& u, const Dual& v) {
  return Dual(u.real - v.real, u.dual - v.dual);
}

Dual operator*(const Dual& u, const Dual& v) {
  return Dual(u.real * v.real, u.dual * v.real + u.real * v.dual);
}

Dual operator/(const Dual& u, const Dual& v) {
  return Dual(u.real / v.real,
              (u.dual * v.real - u.real * v.dual) / (v.real * v.real));
}

std::ostream& operator<<(std::ostream& os, const Dual& d) {
  os << "Real: " << d.real << ", Dual: " << d.dual;
  return os;
}

Dual pow(const Dual& d, const long double& p) {
  return Dual(std::pow(d.real, p), p * d.dual * std::pow(d.real, p - 1));
}

Dual root(const Dual& d, const long double& p) {
  return Dual(std::pow(d.real, 1.0 / p),
              d.dual * 1 / (p * std::pow(std::pow(d.real, 1.0 / p), p - 1)));
}

Dual exp(const Dual& d) {
  return Dual(std::exp(d.real), d.dual * std::exp(d.real));
}

Dual log(const Dual& d) { return Dual(std::log(d.real), d.dual / d.real); }

Dual sin(const Dual& d) {
  return Dual(std::sin(d.real), d.dual * std::cos(d.real));
}

Dual cos(const Dual& d) {
  return Dual(std::cos(d.real), -d.dual * std::sin(d.real));
}

Dual tan(const Dual& d) {
  return Dual(std::tan(d.real), d.dual / (std::pow(std::cos(d.real), 2)));
}

Dual asin(const Dual& d) {
  return Dual(std::asin(d.real), d.dual / std::sqrt(1 - std::pow(d.real, 2)));
}

Dual acos(const Dual& d) {
  return Dual(std::acos(d.real), -d.dual / std::sqrt(1 - std::pow(d.real, 2)));
}

Dual atan(const Dual& d) {
  return Dual(std::atan(d.real), d.dual / (1 + std::pow(d.real, 2)));
}

Dual sinh(const Dual& d) {
  return Dual(std::sinh(d.real), d.dual * std::cosh(d.real));
}

Dual cosh(const Dual& d) {
  return Dual(std::cosh(d.real), d.dual * std::sinh(d.real));
}

Dual tanh(const Dual& d) {
  return Dual(std::tanh(d.real), d.dual / std::pow(std::cosh(d.real), 2));
}
