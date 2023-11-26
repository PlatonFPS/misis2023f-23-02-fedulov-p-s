#include <rational/rational.hpp>
#include <iostream>

int main() {
  Rational a(3);
  Rational b(3, 1);
  std::cout << (a == b) << ' ' << (a != b) << '\n';
  return 0;
}