#include "rational.hpp"

Rational::Rational(const int64_t number)
  : Rational(number, 1) {
}

Rational::Rational(const int64_t number, const int64_t denominator) 
  : num(number)
  , den(denominator) {
}