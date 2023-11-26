#include <rational/rational.hpp>
#include <iostream>

int main() {
  Rational i;
  std::cin >> i;
  std::cout << i << '\n';
  Rational a(3);
  Rational b(3, 1);
  std::cout << (a == b) << ' ' << (a != b) << '\n';
  Rational c(4, 25);
  Rational d(4, 30);
  std::cout << (c <= d) << ' ' << (c <= c) <<  '\n';
  Rational e(1, 3);
  Rational f(1, 6);
  e += f;
  return 0;
}