#include "rational.hpp"

#include <iostream>
#include <sstream>

int64_t GreatestCommonDiviser(const int64_t lhs, const int64_t rhs) {
  if (lhs % rhs == 0) {
    return rhs;
  }
  if (rhs % lhs == 0) {
    return lhs;
  }
  if (lhs > rhs) {
    return GreatestCommonDiviser(lhs % rhs, rhs);
  }
  return GreatestCommonDiviser(lhs, rhs % lhs);
}

int64_t LeastCommonMultiple(const int64_t lhs, const int64_t rhs) {
  return (lhs * rhs) / GreatestCommonDiviser(lhs, rhs);
} 

Rational::Rational(const int64_t number)
  : Rational(number, 1) {
}

Rational::Rational(const int64_t number, const int64_t denominator) 
  : num_(number)
  , den_(denominator) {
  if (denominator == 0) {
    throw std::invalid_argument("Division by zero is not allowed");
  }
  CheckSign();
  SimplifyFraction();
}

void Rational::CheckSign() {
  if (den_ < 0) {
    num_ = -num_;
    den_ = -den_;
  }
  return;
}

void Rational::SimplifyFraction() {
  int64_t greatest_common_diviser = GreatestCommonDiviser(std::abs(num_), den_);
  if (greatest_common_diviser != 1) {
    num_ /= greatest_common_diviser;
    den_ /= greatest_common_diviser;
  }
  return;
}

Rational& Rational::operator+=(const Rational& rhs) {
  if (den_ != rhs.den_) {
    int64_t least_common_multiple = LeastCommonMultiple(den_, rhs.den_);
    num_ *= least_common_multiple / den_;
    den_ = least_common_multiple;
    num_ += rhs.num_ * least_common_multiple / rhs.den_;
  } else {
    num_ += rhs.num_;
  }
  SimplifyFraction();
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) { 
  return operator+=(-rhs); 
}

Rational& Rational::operator*=(const Rational& rhs) {
  num_ *= rhs.num_;
  den_ *= rhs.den_;
  SimplifyFraction();
  return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
  if (rhs.den_ == 0) {
    throw std::invalid_argument("Division by zero is not allowed");
  }
  num_ *= rhs.den_;
  den_ *= rhs.num_;
  CheckSign();
  SimplifyFraction();
  return *this;
}

Rational operator-(const Rational& rhs) { 
  return Rational(-rhs.num(), rhs.den()); 
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
  Rational sum = lhs;
  sum += rhs;
  return sum;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
  Rational sum = lhs;
  sum -= rhs;
  return sum;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
  Rational sum = lhs;
  sum *= rhs;
  return sum;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational sum = lhs;
  sum /= rhs;
  return sum;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
  ostrm << num_ << separator << den_;
  return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) {
  int64_t number = 0;
  char sep = 0;
  int64_t denominator = 1;
  istrm >> number >> sep >> denominator;
  if (istrm.good()) {
    if (sep == Rational::separator) {
      num_ = number;
      den_ = denominator;
      SimplifyFraction();
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}