#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <cstddef>

class DynArr {
public:
  DynArr() = default;
  DynArr(const DynArr& copy) = default;
  DynArr(const ptrdiff_t size);
  ~DynArr() = default;

  DynArr& operator=(const DynArr& value) = default;

  [[nodiscard]] std::ptrdiff_t Size() const;
  void Resize(const std::ptrdiff_t size);

  [[nodiscard]] float& operator[](const std::ptrdiff_t i);
  [[nodiscard]] const float& operator[](const std::ptrdiff_t i) const;

private:
  std::ptrdiff_t size_ = 0;
  float* data_ = nullptr;
};

#endif //DYNARR_HPP