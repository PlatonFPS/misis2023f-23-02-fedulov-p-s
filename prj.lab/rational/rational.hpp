#include <cstdint>

class Rational {
public:
  Rational() = default;
  explicit Rational(const int64_t num);
  Rational(const int64_t num, const int64_t den);


};