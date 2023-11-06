#include <iostream>
#include <sstream>

struct Complex {
  double re{ 0.0 };
  double im{ 0.0 };
  Complex() = default;
  Complex(double real);
  Complex(double real, double imaginary);
  bool operator==(const Complex& rhs);
  bool operator!=(const Complex& rhs);
  Complex& operator+=(const Complex& rhs);
  Complex& operator-=(const Complex& rhs);
  Complex& operator*=(const Complex& rhs);
  std::ostream& WriteToStream(std::ostream& ostrm) const;
  std::istream& ReadFromStream(std::istream& istrm);
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  return rhs.ReadFromStream(istrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
  return rhs.WriteToStream(ostrm);
}

int main() {
  Complex z(5, 7);
  Complex y(8, 2);
  std::cout << "Z = " << z << "; Y = " << y << '\n';
  std::cout << "Addition test:\n";
  std::cout << z << " + " << y << " = " << (z + y) << '\n';
  std::cout << z << " + " << 3 << " = " << (z + 3) << '\n';
  std::cout << 3 << " + " << z << " = " << (3 + z) << '\n';
  std::cout << "Subtraction test:\n";
  std::cout << z << " - " << y << " = " << (z - y) << '\n';
  std::cout << z << " - " << 3 << " = " << (z - 3) << '\n';
  std::cout << 3 << " - " << z << " = " << (3 - z) << '\n';
  std::cout << "Multiplication test:\n";
  std::cout << z << " * " << y << " = " << (z * y) << '\n';
  return 0;
}

Complex::Complex(double real)
  : Complex(real, 0.0) {
}

Complex::Complex(double real, double imaginary)
  : re(real)
  , im(imaginary){
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

Complex operator+(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re + rhs.re, lhs.im + rhs.im);
}

Complex& Complex::operator-=(const Complex& rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this; 
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re - rhs.re, lhs.im - rhs.im);
}

Complex& Complex::operator*=(const Complex& rhs) {
  re = re * rhs.re - im * rhs.im;
  im = im * rhs.re + re * rhs.im;
  return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
  Complex product(lhs);
  product *= rhs;
  return product;
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
