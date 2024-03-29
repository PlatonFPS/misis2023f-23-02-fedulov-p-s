#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <rational/rational.hpp>

#include <iostream>

bool TestParse(const std::string& str) {
  std::istringstream istrm(str);
  Rational q;
  istrm >> q;
  bool stream_good = !istrm.fail() || (istrm.eof() && !istrm.fail());
  if (stream_good) {
    std::cout << "Read success: " << str << " -> " << q << '\n';
  }
  else {
    std::cout << "Read error : " << str << " -> " << q << '\n';
  }
  return stream_good;
}

TEST_CASE("rational constructor") {
  Rational r_def;
  CHECK(0 == r_def.num());
  CHECK(1 == r_def.den());

  Rational r_int(3);
  CHECK(3 == r_int.num());
  CHECK(1 == r_int.den());

  CHECK_THROWS(Rational(1, 0));
}

TEST_CASE("rational input") {
  CHECK(TestParse("1/0") == false);
  CHECK(TestParse("1/2"));
  CHECK(TestParse(" 1/2"));
  CHECK(TestParse("1/2 "));
  CHECK(TestParse(" 1/2 "));
  CHECK(TestParse(" 1 /2 ") == false);
}

TEST_CASE("rational comparison") {
  Rational lhs(4, 19);
  Rational rhs(-2, 8);
  CHECK(rhs == Rational(-1, 4));
  CHECK((-rhs == Rational(1, 4)));

  CHECK(rhs != lhs);

  CHECK(lhs >= Rational(4, 20));
  CHECK(lhs <= Rational(5, 20));

  CHECK(lhs > Rational(-2, 3));
  CHECK(lhs > Rational(2, -3));

  CHECK((Rational(-3, -5) > rhs));
}

TEST_CASE("rational arithmetics") {
  Rational lhs(6, 9);
  Rational rhs(3, 17);

  CHECK(((lhs + rhs) == Rational(43, 51)));
  CHECK(((lhs - rhs) == Rational(25, 51)));
  CHECK(((lhs * rhs) == Rational(6, 51)));
  CHECK(((lhs / rhs) == Rational(34, 9)));

  Rational r_negative(3, -1);
  CHECK(((lhs + r_negative) == Rational(-7, 3)));
  CHECK(((lhs - r_negative) == Rational(11, 3)));
  CHECK(((lhs * r_negative) == Rational(-2, 1)));
  CHECK(((lhs / r_negative) == Rational(-2, 9)));
}