#include <complex/complex.hpp>

#include <iostream>

void InputTest() {
  std::cout << "Input Test:\n";
  TestParse("{2, 4}");
  TestParse("{6,2}");
  TestParse("{2 4}");
  std::cout << '\n';
}

void AdditionTest(const Complex& z, const Complex& y, Complex& x) {
  std::cout << "Addition test:\n";
  std::cout << z << " + " << y << " = " << (z + y) << "; Expected: {13, 9}" << '\n';
  x = z;
  x += y;
  std::cout << z << " += " << y << " -> " << x << "; Expected: {13, 9}" << '\n';
  std::cout << z << " + " << 3 << " = " << (z + 3) << "; Expected: {8, 7}" << '\n';
  x = z;
  x += 3;
  std::cout << z << " += " << 3 << " -> " << x << "; Expected: {8, 7}" << '\n';
  std::cout << 3 << " + " << z << " = " << (3 + z) << "; Expected: {8, 7}" << '\n';
  std::cout << '\n';
}

void SubstractionTest(const Complex& z, const Complex& y, Complex& x) {
  std::cout << "Subtraction test:\n";
  std::cout << z << " - " << y << " = " << (z - y) << "; Expected: {-3, 5}" << '\n';
  x = z;
  x -= y;
  std::cout << z << " -= " << y << " -> " << x << "; Expected: {-3, 5}" << '\n';
  std::cout << z << " - " << 3 << " = " << (z - 3) << "; Expected: {2, 7}" << '\n';
  x = z;
  x -= 3;
  std::cout << z << " -= " << 3 << " -> " << x << "; Expected: {2, 7}" << '\n';
  std::cout << 3 << " - " << z << " = " << (3 - z) << "; Expected: {-2, -7}" << '\n';
  std::cout << '\n';
}

void MultiplicationTest(const Complex& z, const Complex& y, Complex& x) {
  std::cout << "Multiplication test:\n";
  std::cout << z << " * " << y << " = " << (z * y) << "; Expected: {26, 66}" << '\n';
  x = z;
  x *= y;
  std::cout << z << " *= " << y << " -> " << x << "; Expected: {26, 66}" << '\n';
  std::cout << z << " * " << 3 << " = " << (z * 3) << "; Expected: {15, 21}" << '\n';
  x = z;
  x *= 3;
  std::cout << z << " *= " << 3 << " -> " << x << "; Expected: {15, 21}" << '\n';
  std::cout << 3 << " * " << z << " = " << (3 * z) << "; Expected: {15, 21}" << '\n';
  std::cout << 0 << " * " << z << " = " << (0 * z) << "; Expected: {0, 0}" << '\n';
  std::cout << '\n';
}

void DivisionTest(const Complex& z, const Complex& y, Complex& x) {
  std::cout << "Division test:\n";
  std::cout << z << " / " << y << " = " << (z / y) << "; Expected: {0.794118, 0.676471}" << '\n';
  x = z;
  x /= y;
  std::cout << z << " /= " << y << " -> " << x << "; Expected: {0.794118, 0.676471}" << '\n';
  std::cout << z << " / " << 3 << " = " << (z / 3) << "; Expected: {1.6667, 2.3333}" << '\n';
  x = z;
  x /= 3;
  std::cout << z << " /= " << 3 << " -> " << x << "; Expected: {1.6667, 2.3333}" << '\n';
  std::cout << z << " / " << y << " * " << y << " = " << ((z / y) * y) << "; Expected: {5, 7}" << '\n';
  try {
    std::cout << z << " / " << 0;
    z / 0;
    std::cout << " = " << (z / 0) << '\n';
  }
  catch (const std::invalid_argument& e) {
    std::cout << " -> Exception was thrown: " << e.what() << '\n';
  }
  std::cout << '\n';
}

void AriphmeticsTest() {
  std::cout << "Arithmetics test:\n";
  Complex z(5, 7);
  Complex y(8, 2);
  Complex x(0, 0);
  std::cout << "Z = " << z << "; Y = " << y << '\n';
  std::cout << z.Conjugate() << " is conjugate number to " << z << '\n';
  std::cout << y.Conjugate() << " is conjugate number to " << y << '\n';
  std::cout << "-" << z << " = " << -z << '\n';
  std::cout << '\n';
  AdditionTest(z, y, x);
  SubstractionTest(z, y, x);
  MultiplicationTest(z, y, x);
  DivisionTest(z, y, x);
}

int main() {
  InputTest();
  AriphmeticsTest();
  return 0;
}