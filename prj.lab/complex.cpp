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
  std::ostream& WriteToStream(std::ostream& ostrm);
  std::istream& ReadFromStream(std::istream& istrm);
};

Complex operator+(const Complex& lhs, const Complex& rhs);
Complex operator-(const Complex& lhs, const Complex& rhs);
Complex operator*(const Complex& lhs, const Complex& rhs);

std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  return rhs.ReadFromStream(istrm);
}

std::ostream& operator<<(std::ostream& ostrm, Complex& rhs) {
  return rhs.WriteToStream(ostrm);
}

int main() {
  Complex z;
  std::cin >> z;
  Complex y;
  std::cin >> y;
  std::cout << z << ' ' << y << '\n';
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
  return Complex(lhs.re + rhs.re, lhs.im + rhs.re);
}

Complex& Complex::operator-=(const Complex& rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this; 
}

Complex operator-(const Complex& lhs, const Complex& rhs) {
  return Complex(lhs.re - rhs.re, lhs.im - rhs.re);
}

Complex& Complex::operator*=(const Complex& rhs) {
  re = re * rhs.re - im * rhs.im;
  im = re * rhs.re + im * rhs.im;
  return *this;
}

Complex operator*(const Complex& lhs, const Complex& rhs) {
  Complex product(lhs);
  product *= lhs;
  return product;
}

std::ostream& Complex::WriteToStream(std::ostream& ostrm) {
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
