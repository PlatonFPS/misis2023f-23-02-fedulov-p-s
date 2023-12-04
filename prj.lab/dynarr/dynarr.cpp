#include "dynarr.hpp"

#include <iostream>

float value = 0;
const float kValue = 0;

DynArr::DynArr(const ptrdiff_t size)
  : size_(size) {
}

std::ptrdiff_t DynArr::Size() const {
  return size_;
}

void DynArr::Resize(const std::ptrdiff_t size) {
  if (size <= 0) {
    throw std::invalid_argument("Non-positive size is not allowed");
  } 
  size_ = size;
  return;
}

float& DynArr::operator[](const std::ptrdiff_t i) {
  if (i >= size_) {
    throw std::invalid_argument("Index out of range");
  }
  return value;
}

const float& DynArr::operator[](const std::ptrdiff_t i) const {
  if (i >= size_) {
    throw std::invalid_argument("Index out of range");
  }
  return kValue;
}

