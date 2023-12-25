#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <stdexcept>
#include <cstddef>

class DynArr {
public:
  [[nodiscard]] DynArr() = default;
  [[nodiscard]] explicit DynArr(const DynArr& copy);
  [[nodiscard]] explicit DynArr(const ptrdiff_t size);
  ~DynArr();

  DynArr& operator=(const DynArr& value);

  [[nodiscard]] std::ptrdiff_t Size() const noexcept { return size_; }
  [[nodiscard]] std::ptrdiff_t Capacity() const noexcept { return capacity_; }

  void Resize(const std::ptrdiff_t size);

  [[nodiscard]] float& operator[](const std::ptrdiff_t i);
  [[nodiscard]] const float& operator[](const std::ptrdiff_t i) const;

private:
  std::ptrdiff_t size_ = 0;
  std::ptrdiff_t capacity_ = 0;
  float* data_ = nullptr;
  float default_value = 0;
};

#endif //DYNARR_HPP