#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <rational/rational.hpp>

#include <iostream>

TEST_CASE("rational constructor") {
  Rational r_def;
  CHECK(0 == r_def.num());
  CHECK(1 == r_def.den());

  Rational r_int(3);
  CHECK(3 == r_int.num());
  CHECK(1 == r_int.den());

  CHECK_THROWS(Rational(1, 0));
}