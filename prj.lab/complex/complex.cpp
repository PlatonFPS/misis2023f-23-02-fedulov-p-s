#include "complex.hpp"
#include <iostream>

bool TestParse(const std::string& str) {
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

Complex Complex::Conjugate() const {
  return Complex(re, -im);
}

bool Complex::operator==(const Complex& rhs) {
  return re == rhs.re && im == rhs.im;
}

bool Complex::operator!=(const Complex& rhs) {
  return !operator==(rhs);
}

Complex& Complex::operator+=(const Complex& rhs) {
  re += rhs.re;
  im += rhs.im;
  return *this;
}

Complex& Complex::operator+=(const double rhs) {
  re += rhs;
  return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator+(const Complex& lhs, const double rhs) {
  return lhs + Complex(rhs);
}

Complex operator+(const double lhs, const Complex& rhs) {
  return Complex(rhs) + lhs;
}

Complex& Complex::operator-=(const Complex& rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}

Complex& Complex::operator-=(const double rhs) {
  re -= rhs;
  return *this;
}

Complex operator-(const Complex& rhs) {
  Complex neggative(-rhs.re, -rhs.im);
  return neggative;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator-(const Complex& lhs, const double rhs) {
  return lhs - Complex(rhs);
}

Complex operator-(const double lhs, const Complex& rhs) {
  return Complex(lhs) - rhs;
}

Complex& Complex::operator*=(const Complex& rhs) {
  double real = re * rhs.re - im * rhs.im;
  im = im * rhs.re + re * rhs.im;
  re = real;
  return *this;
}

Complex& Complex::operator*=(const double rhs) {
  re *= rhs;
  im *= rhs;
  return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
  Complex product(lhs);
  product *= rhs;
  return product;
}

Complex operator*(const Complex& lhs, const double rhs) {
  return lhs * Complex(rhs);
}

Complex operator*(const double lhs, const Complex& rhs) {
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

std::ostream& Complex::WriteToStream(std::ostream& ostrm) const {
  ostrm << '{' << re << ',' << im << '}';
  return ostrm;
}

std::istream& Complex::ReadFromStream(std::istream& istrm) {
  char left_brase = '.';
  double real = 0.0;
  char comma = ',';
  double imaginary = 0.0;
  char right_brase = '.';
  istrm >> left_brase >> real >> comma >> imaginary >> right_brase;
  if (istrm.good()) {
    if (left_brase == '{' && comma == ',' && right_brase == '}') {
      re = real;
      im = imaginary;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}