#include <iostream>
#include <sstream>

struct Complex {
  double re{ 0.0 };
  double im{ 0.0 };
  Complex() = default;
  explicit Complex(double real);
  Complex(double real, double imaginary);
  Complex(const Complex& c) = default;
  ~Complex() = default;
  inline Complex Conjugate() const;
  Complex& operator=(const Complex& copy) = default;
  bool operator==(const Complex& rhs);
  bool operator!=(const Complex& rhs);
  Complex& operator+=(const Complex& rhs);
  Complex& operator+=(const double rhs);
  Complex& operator-=(const Complex& rhs);
  Complex& operator-=(const double rhs);
  Complex& operator*=(const Complex& rhs);
  Complex& operator*=(const double rhs);
  Complex& operator/=(double rhs);
  Complex& operator/=(const Complex& rhs);
  std::ostream& WriteToStream(std::ostream& ostrm) const;
  std::istream& ReadFromStream(std::istream& istrm);
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator+(const Complex& lhs, const double rhs);
Complex operator+(const double lhs, const Complex& rhs);
Complex operator-(const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const double rhs);
Complex operator-(const double lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const double rhs);
Complex operator*(const double lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const Complex& rhs);
Complex operator/(const Complex& lhs, const double rhs);

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  return rhs.ReadFromStream(istrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
  return rhs.WriteToStream(ostrm);
}

bool TestParse(const std::string& str) {
  std::istringstream istrm(str);
  Complex z;
  istrm >> z;
  if (istrm.good()) {
    std::cout << "Read Success: ";
  }
  else {
    std::cout << "Read Error: ";
  }
  std::cout << "read " << z << " from " << str << '\n';
  return istrm.good();
}

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
  try {
    std::cout << z << " / " << y << " = " << (z / y) << "; Expected: {0.794118, 0.676471}" << '\n';
    x = z;
    x /= y;
    std::cout << z << " /= " << y << " -> " << x << "; Expected: {0.794118, 0.676471}" << '\n';
    std::cout << z << " / " << 3 << " = " << (z / 3) << "; Expected: {1.6667, 2.3333}" << '\n';
    x = z;
    x /= 3;
    std::cout << z << " /= " << 3 << " -> " << x << "; Expected: {1.6667, 2.3333}" << '\n';
    std::cout << z << " / " << y << " * " << y << " = " << ((z / y) * y) << "; Expected: {5, 7}" << '\n';
    std::cout << z << " / " << 0 << " = " << (z / 0) << '\n';
  }
  catch (const std::exception& e) {
    std::cout << e.what() << '\n';
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

Complex::Complex(double real)
  : Complex(real, 0.0) {
}

Complex::Complex(double real, double imaginary)
  : re(real)
  , im(imaginary){
}

Complex Complex::Conjugate() const {
  return Complex(re, -im);
}

bool Complex::operator==(const Complex& rhs) {
  return re == rhs.re && im == rhs.im;
}

bool Complex::operator!=(const Complex& rhs) {
  return !operator==(rhs);
}

Complex& Complex::operator+=(const Complex& rhs) {
  re += rhs.re;
  im += rhs.im;
  return *this;
}

Complex& Complex::operator+=(const double rhs) {
  re += rhs;
  return *this;
}

Complex operator+(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex operator+(const Complex& lhs, const double rhs) {
  return lhs + Complex(rhs);
}

Complex operator+(const double lhs, const Complex& rhs) {
  return Complex(rhs) + lhs;
}

Complex& Complex::operator-=(const Complex& rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this; 
}

Complex& Complex::operator-=(const double rhs) {
  re -= rhs;
  return *this;
}

Complex operator-(const Complex& rhs) {
  Complex neggative(-rhs.re, -rhs.im);
  return neggative;
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex operator-(const Complex& lhs, const double rhs) {
  return lhs - Complex(rhs);
}

Complex operator-(const double lhs, const Complex& rhs) {
  return Complex(lhs) - rhs;
}

Complex& Complex::operator*=(const Complex& rhs) {
  double real = re * rhs.re - im * rhs.im;
  im = im * rhs.re + re * rhs.im;
  re = real;
  return *this;
}

Complex& Complex::operator*=(const double rhs) {
  re *= rhs;
  im *= rhs;
  return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
  Complex product(lhs);
  product *= rhs;
  return product;
}

Complex operator*(const Complex& lhs, const double rhs) {
  return lhs * Complex(rhs);
}

Complex operator*(const double lhs, const Complex& rhs) {
  return Complex(lhs) * rhs;
}

Complex& Complex::operator/=(double rhs) {
  if (rhs == 0) {
    throw std::exception("Division by zero is not allowed");
  }
  re /= rhs;
  im /= rhs;
  return *this;
}

Complex& Complex::operator/=(const Complex& rhs) {
  if (rhs.re == 0 && rhs.im == 0) {
    throw std::exception("Division by zero is not allowed");
  }
  double denominator = rhs.re * rhs.re + rhs.im * rhs.im;
  if (denominator != 0) {
    *this *= rhs.Conjugate();
    *this /= denominator;
    return *this;
  }
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
  Complex quotient = lhs;
  quotient /= rhs;
  return quotient;
}

Complex operator/(const Complex& lhs, const double rhs) {
  return lhs / Complex(rhs);
}

std::ostream& Complex::WriteToStream(std::ostream& ostrm) const {
  ostrm << '{' << re << ',' << im << '}';
  return ostrm;
}

std::istream& Complex::ReadFromStream(std::istream& istrm) {
  char left_brase = '.';
  double real = 0.0;
  char comma = ',';
  double imaginary = 0.0;
  char right_brase = '.';
  istrm >> left_brase >> real >> comma >> imaginary >> right_brase;
  if (istrm.good()) {
    if (left_brase == '{' && comma == ',' && right_brase == '}') {
      re = real;
      im = imaginary;
    }
    else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}
