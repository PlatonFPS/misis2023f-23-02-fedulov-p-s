#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <stdexcept>
#include <cstddef>

class DynArr {
public:
  DynArr() = default;
  explicit DynArr(const DynArr& copy);
  explicit DynArr(const ptrdiff_t size);
  ~DynArr();

  void operator=(const DynArr& value);

  [[nodiscard]] std::ptrdiff_t Size() const { return size_; }
  [[nodiscard]] std::ptrdiff_t Capacity() const { return capacity_; }

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