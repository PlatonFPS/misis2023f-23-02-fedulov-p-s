#include "dynarr.hpp"

#include <cstring>

DynArr::DynArr(const DynArr& copy) 
  : size_(copy.Size())
  , capacity_(size_) {
  data_ = new float[size_];
  std::memcpy(data_, copy.data_, sizeof(float) * size_);
}

DynArr::DynArr(const ptrdiff_t size) {
  if (size <= 0) {
    throw std::invalid_argument("Non-positive size is not allowed");
  }
  size_ = size;
  capacity_ = size_;
  data_ = new float[size_];
  for (int i_float = 0; i_float < size_; i_float += 1) {
    *(data_ + i_float) = default_value;
  }
}

DynArr::~DynArr() {
  delete[] data_;
  data_ = nullptr;
  capacity_ = 0;
  size_ = 0;
}

void DynArr::Resize(const std::ptrdiff_t size) {
  if (size <= 0) {
    throw std::invalid_argument("Non-positive size is not allowed");
  } 
  if (capacity_ > size) {
    for (int i_float = size; i_float < size_; i_float += 1) {
      *(data_ + i_float) = default_value;
    }
  } else {
    float* temp_data = new float[size];
    for (int i_float = 0; i_float < size_; i_float += 1) {
      *(temp_data + i_float) = *(data_ + i_float);
    }
    for (int i_float = size_; i_float < size; i_float += 1) {
      *(temp_data + i_float) = default_value;
    }
    delete[] data_;
    data_ = temp_data;
    capacity_ = size;
  }
  size_ = size;
  return;
}

void DynArr::operator=(const DynArr& value) {
  delete[] data_;
  size_ = value.Size();
  capacity_ = value.Capacity();
  data_ = new float[size_];
  std::memcpy(data_, value.data_, sizeof(float) * size_);
}

float& DynArr::operator[](const std::ptrdiff_t index) {
  if (index >= size_ || index < 0) {
    throw std::invalid_argument("Index out of range");
  }
  return *(data_ + index);
}

const float& DynArr::operator[](const std::ptrdiff_t index) const {
  if (index >= size_ || index < 0) {
    throw std::invalid_argument("Index out of range");
  }
  return *(data_ + index);
}

