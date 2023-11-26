#include <rational/rational.hpp>
#include <iostream>

int main() {
  Rational a(3);
  Rational b(3, 1);
  std::cout << (a == b) << ' ' << (a != b) << '\n';
  Rational c(4, 25);
  Rational d(4, 30);
  std::cout << (c <= d) << ' ' << (c <= c) <<  '\n';
  return 0;
}