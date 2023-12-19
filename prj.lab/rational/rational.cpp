#include "rational.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

int64_t GreatestCommonDiviser(const int64_t lhs, const int64_t rhs) noexcept {
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

int64_t LeastCommonMultiple(const int64_t lhs, const int64_t rhs) noexcept {
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

void Rational::CheckSign() noexcept {
  if (den_ < 0) {
    num_ = -num_;
    den_ = -den_;
  }
  return;
}

void Rational::SimplifyFraction() noexcept {
  int64_t greatest_common_diviser = GreatestCommonDiviser(std::abs(num_), den_);
  if (greatest_common_diviser != 1) {
    num_ /= greatest_common_diviser;
    den_ /= greatest_common_diviser;
  }
  return;
}

bool Rational::operator==(const Rational& rhs) const noexcept {
  return num_ == rhs.num_ && den_ == rhs.den_; 
}

bool Rational::operator!=(const Rational& rhs) const noexcept { 
  return !(operator==(rhs)); 
}

bool Rational::operator==(const int64_t rhs) const noexcept { 
  return operator==(Rational(rhs)); 
}

bool Rational::operator!=(const int64_t rhs) const noexcept { 
  return operator!=(Rational(rhs)); 
}

bool Rational::operator<(const Rational& rhs) const noexcept { 
  return num_ * rhs.den_ < rhs.num_ * den_; 
}

bool Rational::operator<(const int64_t rhs) const noexcept { 
  return operator<(Rational(rhs)); 
}

bool Rational::operator<=(const Rational& rhs) const noexcept { 
  return operator<(rhs) || operator==(rhs); 
}

bool Rational::operator<=(const int64_t rhs) const noexcept { 
  return operator<=(Rational(rhs)); 
}
bool Rational::operator>(const Rational& rhs) const noexcept { 
  return num_ * rhs.den_ > rhs.num_ * den_; 
}

bool Rational::operator>(const int64_t rhs) const noexcept { 
  return operator>(Rational(rhs)); 
}

bool Rational::operator>=(const Rational& rhs) const noexcept { 
  return operator>(rhs) || operator==(rhs); 
}

bool Rational::operator>=(const int64_t rhs) const noexcept { 
  return operator>=(Rational(rhs)); 
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
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

Rational& Rational::operator-=(const Rational& rhs) noexcept {
  return operator+=(-rhs);
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
  num_ *= rhs.num_;
  den_ *= rhs.den_;
  SimplifyFraction();
  return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
  if (rhs.num_ == 0) {
    throw std::invalid_argument("Division by zero is not allowed");
  }
  num_ *= rhs.den_;
  den_ *= rhs.num_;
  CheckSign();
  SimplifyFraction();
  return *this;
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
  Rational sum = lhs;
  sum += rhs;
  return sum;
}

[[nodiscard]] Rational operator+(const Rational& lhs, const int64_t rhs) noexcept {
  return lhs + Rational(rhs);
}

[[nodiscard]] Rational operator+(const int64_t lhs, const Rational& rhs) noexcept {
  return Rational(lhs) + rhs;
}

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
  Rational sum = lhs;
  sum -= rhs;
  return sum;
}

[[nodiscard]] Rational operator-(const Rational& lhs, const int64_t rhs) noexcept {
  return lhs - Rational(rhs);
}

[[nodiscard]] Rational operator-(const int64_t lhs, const Rational& rhs) noexcept {
  return Rational(lhs) - rhs;
}

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
  Rational sum = lhs;
  sum *= rhs;
  return sum;
}

[[nodiscard]] Rational operator*(const Rational& lhs, const int64_t rhs) noexcept {
  return lhs * Rational(rhs);
}

[[nodiscard]] Rational operator*(const int64_t lhs, const Rational& rhs) noexcept {
  return Rational(lhs) * rhs;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational sum = lhs;
  sum /= rhs;
  return sum;
}

[[nodiscard]] Rational operator/(const Rational& lhs, const int64_t rhs) {
  return lhs / Rational(rhs);
}

[[nodiscard]] Rational operator/(const int64_t lhs, const Rational& rhs) {
  return Rational(lhs) / rhs;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
  ostrm << num_ << separator << den_;
  return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) noexcept {
  int64_t num(0);
  char delimiter(0);
  int64_t den(1);
  istrm >> num;
  istrm.get(delimiter);
  int64_t trash = istrm.peek();
  istrm >> den;
  if (!istrm || trash > '9' || trash < '0') {
    istrm.setstate(std::ios_base::failbit);
    return istrm;
  }
  if (istrm.good() || istrm.eof()) {
    if ('/' == delimiter && den > 0) {
      *this = Rational(num, den);
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}
