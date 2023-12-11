#include "complex.hpp"

#include <iostream>
#include <sstream>

bool TestParse(const std::string& str) noexcept {
  std::istringstream istrm(str);
  Complex z;
  istrm >> z;
  if (istrm.good()) {
    std::cout << "Read Success: ";
  }
  else {
    std::cout << "Read Error: ";
  }
  std::cout << "read " << z << " from " << str << '\n';
  return istrm.good();
}

Complex::Complex(double real)
  : Complex(real, 0.0) {
}

Complex::Complex(double real, double imaginary)
  : re(real)
  , im(imaginary) {
}

Complex Complex::Conjugate() const noexcept {
  return Complex(re, -im);
}

bool Complex::operator==(const Complex& rhs) noexcept {
  return re == rhs.re && im == rhs.im;
}

bool Complex::operator!=(const Complex& rhs) noexcept {
  return !operator==(rhs);
}

Complex& Complex::operator+=(const Complex& rhs) noexcept {
  re += rhs.re;
  im += rhs.im;
  return *this;
}

Complex& Complex::operator+=(const double rhs) noexcept {
  re += rhs;
  return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
  return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator+(const Complex& lhs, const double rhs) noexcept {
  return lhs + Complex(rhs);
}

Complex operator+(const double lhs, const Complex& rhs) noexcept {
  return Complex(rhs) + lhs;
}

Complex& Complex::operator-=(const Complex& rhs) noexcept {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}

Complex& Complex::operator-=(const double rhs) noexcept {
  re -= rhs;
  return *this;
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
  return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator-(const Complex& lhs, const double rhs) noexcept {
  return lhs - Complex(rhs);
}

Complex operator-(const double lhs, const Complex& rhs) noexcept {
  return Complex(lhs) - rhs;
}

Complex& Complex::operator*=(const Complex& rhs) noexcept {
  double real = re * rhs.re - im * rhs.im;
  im = im * rhs.re + re * rhs.im;
  re = real;
  return *this;
}

Complex& Complex::operator*=(const double rhs) noexcept {
  re *= rhs;
  im *= rhs;
  return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
  Complex product(lhs);
  product *= rhs;
  return product;
}

Complex operator*(const Complex& lhs, const double rhs) noexcept {
  return lhs * Complex(rhs);
}

Complex operator*(const double lhs, const Complex& rhs) noexcept {
  return Complex(lhs) * rhs;
}

Complex& Complex::operator/=(double rhs) {
  if (rhs == 0) {
    throw std::invalid_argument("Division by zero is not allowed");
  }
  re /= rhs;
  im /= rhs;
  return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
  if (rhs.re == 0 && rhs.im == 0) {
    throw std::invalid_argument("Division by zero is not allowed");
  }
  double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
  if (denominator != 0) {
    *this *= rhs.Conjugate();
    *this /= denominator;
    return *this;
  } else {
    throw std::invalid_argument("Non-zero denominator is required");
  }
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  Complex quotient = lhs;
  quotient /= rhs;
  return quotient;
}

Complex operator/(const Complex& lhs, const double rhs) {
  return lhs / Complex(rhs);
}

Complex operator/(const double lhs, const Complex& rhs) {
  return Complex(lhs) / rhs;
}

std::ostream& Complex::WriteToStream(std::ostream& ostrm) const noexcept {
  ostrm << Complex::leftBrace << re << Complex::separator << im << Complex::rightBrace;
  return ostrm;
}

std::istream& Complex::ReadFromStream(std::istream& istrm) noexcept {
  char left_brase = 0;
  double real = 0.0;
  char comma = 0;
  double imaginary = 0.0;
  char right_brase = 0;
  istrm >> left_brase >> real >> comma >> imaginary >> right_brase;
  if (istrm.good()) {
    if (left_brase == Complex::leftBrace && comma == Complex::separator && right_brase == Complex::rightBrace) {
      re = real;
      im = imaginary;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}