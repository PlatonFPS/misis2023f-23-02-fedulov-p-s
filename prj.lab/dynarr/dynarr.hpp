#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <cstddef>

class DynArr {
public:
  DynArr() = default;
  //DynArr(const DynArr& copy);
  //DynArr(const ptrdiff_t size);
  //~DynArr();

  //DynArr& operator=(const DynArr& value);

  std::ptrdiff_t Size() const;
  void Resize(const std::ptrdiff_t size);

  float& operator[](const std::ptrdiff_t i);
  const float& operator[](const std::ptrdiff_t i) const;

private:
  std::ptrdiff_t size_ = 0;
  float* data_ = nullptr;
};

#endif //DYNARR_HPP