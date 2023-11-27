#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdint>
#include <sstream>

class Rational {
public:
  Rational() = default;
  explicit Rational(const int64_t number);
  Rational(const int64_t number, const int64_t denominator);

  void CheckSign();
  void SimplifyFraction();

  int64_t num() const { return num_; }
  int64_t den() const { return den_; }

  bool operator==(const Rational& rhs) { return num_ == rhs.num_ && den_ == rhs.den_; }
  bool operator==(const int64_t rhs) { return operator==(Rational(rhs)); }
  bool operator!=(const Rational& rhs) { return !(operator==(rhs)); }
  bool operator!=(const int64_t rhs) { return operator!=(Rational(rhs)); }
  bool operator<(const Rational& rhs) { return num_ * rhs.den_ < rhs.num_ * den_; }
  bool operator<(const int64_t rhs) { return operator<(Rational(rhs)); }
  bool operator<=(const Rational& rhs) { return operator<(rhs) || operator==(rhs); }
  bool operator<=(const int64_t rhs) { return operator<=(Rational(rhs)); }
  bool operator>(const Rational& rhs) { return num_ * rhs.den_ > rhs.num_ * den_; }
  bool operator>(const int64_t rhs) { return operator>(Rational(rhs)); }
  bool operator>=(const Rational& rhs) { return operator>(rhs) || operator==(rhs); }
  bool operator>=(const int64_t rhs) { return operator>=(Rational(rhs)); }

  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int64_t rhs) { return operator+=(Rational(rhs)); }
  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int64_t rhs) { return operator-=(Rational(rhs)); }
  Rational& operator*=(const Rational& rhs);
  Rational& operator*=(const int64_t rhs) { return operator*=(Rational(rhs)); }
  Rational& operator/=(const Rational& rhs);
  Rational& operator/=(const int64_t rhs) { return operator/=(Rational(rhs)); }

  std::ostream& WriteTo(std::ostream& ostrm) const;
  std::istream& ReadFrom(std::istream& istrm);
private:
  int64_t num_ = 0;
  int64_t den_ = 1;
  static const char separator = '/';
};

Rational operator-(const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
  return rhs.WriteTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
  return rhs.ReadFrom(istrm);
}
#endif //RATIONAL_HPP