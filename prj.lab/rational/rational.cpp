#include "rational.hpp"
#include <iostream>

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
  //implement dividing num and den by the greatest common diviser
}