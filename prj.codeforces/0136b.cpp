#include <iostream>

int main() {
  //a tor b = c
  int a = 0;
  int c = 0;
  std::cin >> a >> c;
  int b = 0;
  int power_of_3 = 1;
  while (a != 0 || c != 0) {
    int next_digit = 0;
    if (a % 3 > c % 3) {
      next_digit = (c % 3) + 3 - (a % 3);
    }
    else {
      next_digit = (c % 3) - (a % 3);
    }
    b = next_digit * power_of_3 + b;
    power_of_3 *= 3;
    a /= 3;
    c /= 3;
  }
  std::cout << b << '\n';
  return 0;
}