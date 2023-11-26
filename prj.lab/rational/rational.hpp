#include <cstdint>

class Rational {
public:
  Rational() = default;
  explicit Rational(const int64_t number);
  Rational(const int64_t number, const int64_t denominator);

  int64_t GetNum() { return num; }
  int64_t GetDen() { return den; }

  bool operator==(const Rational& rhs) { return num == rhs.num && den == rhs.den; }
  bool operator==(const int64_t rhs) { return operator==(Rational(rhs)); }
  bool operator!=(const Rational& rhs) { return !(operator==(rhs)); }
  bool operator!=(const int64_t rhs) { return operator!=(Rational(rhs)); }
  bool operator<(const Rational& rhs) { return num * rhs.den < rhs.num * den; }
  bool operator<(const int64_t rhs) { return operator<(Rational(rhs)); }
  bool operator<=(const Rational& rhs) { return operator<(rhs) || operator==(rhs); }
  bool operator<=(const int64_t rhs) { return operator<=(Rational(rhs)); }
  bool operator>(const Rational& rhs) { return num * rhs.den > rhs.num * den; }
  bool operator>(const int64_t rhs) { return operator>(Rational(rhs)); }
  bool operator>=(const Rational& rhs) { return operator>(rhs) || operator==(rhs); }
  bool operator>=(const int64_t rhs) { return operator>=(Rational(rhs)); }

private:
  int64_t num = 0;
  int64_t den = 1;
};