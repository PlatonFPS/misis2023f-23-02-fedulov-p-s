#ifndef COMPLEX_HPP
#define COMPLEX_HPP
#include<sstream>

struct Complex {
  double re{ 0.0 };
  double im{ 0.0 };
  Complex() = default;
  explicit Complex(double real);
  explicit Complex(double real, double imaginary);
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

bool TestParse(const std::string& str);

inline std::istream& operator>>(std::istream& istrm, Complex& rhs) {
  return rhs.ReadFromStream(istrm);
}

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) {
  return rhs.WriteToStream(ostrm);
}
#endif 