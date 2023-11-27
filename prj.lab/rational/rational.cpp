#include "rational.hpp"

#include <iostream>

int64_t GreatestCommonDiviser(const int64_t lhs, const int64_t rhs) {
  if (lhs % rhs == 0) return rhs;
  if (rhs % lhs == 0) return lhs;
  if (lhs > rhs) return GreatestCommonDiviser(lhs % rhs, rhs);
  return GreatestCommonDiviser(lhs, rhs % lhs);
}

int64_t LeastCommonMultiple(const int64_t lhs, const int64_t rhs) {
  return (lhs * rhs) / GreatestCommonDiviser(lhs, rhs);
} 

Rational::Rational(const int64_t number)
  : Rational(number, 1) {
}

Rational::Rational(const int64_t number, const int64_t denominator) 
  : num(number)
  , den(denominator) {
  if (denominator == 0) {
    throw std::invalid_argument("Division by zero is not allowed");
  }
  if (den < 0) {
    num = -num;
    den = -den;
  }
  SimplifyFraction();
}

void Rational::SimplifyFraction() {
  int64_t greatest_common_diviser = GreatestCommonDiviser(std::abs(num), den);
  if (greatest_common_diviser != 1) {
    num /= greatest_common_diviser;
    den /= greatest_common_diviser;
  }
}

Rational& Rational::operator+=(const Rational& rhs) {
  if (den != rhs.den) {
    int64_t least_common_multiple = LeastCommonMultiple(den, rhs.den);
    num *= least_common_multiple / den;
    den = least_common_multiple;
    num += rhs.num * least_common_multiple / rhs.den;
  }
  else {
    num += rhs.num;
  }
  SimplifyFraction();
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) { return operator+=(-rhs); }

Rational operator-(const Rational& rhs) { return Rational(-rhs.GetNum(), rhs.GetDen()); }

std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
  ostrm << num << separator << den;
  return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) {
  int64_t number = 0;
  char sep = '.';
  int64_t denominator = 1;
  istrm >> number >> sep >> denominator;
  if (istrm.good()) {
    if (sep == Rational::separator) {
      num = number;
      den = denominator;
      SimplifyFraction();
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}