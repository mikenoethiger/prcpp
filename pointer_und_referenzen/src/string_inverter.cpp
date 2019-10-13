#include "string_inverter.h"
#include <cassert>

StringInverter::StringInverter(std::string_view init)
    : count_(init.size()) {
  data_ = new char[count_ + 1]; // +1 for the terminator null
  assert(data_ != nullptr); // check that memory allocation worked properly

  for (size_t i = 0; i < count_; ++i) {
    data_[i] = init[i];
  }

  data_[count_] = 0;
}
StringInverter::~StringInverter() {
  delete[] data_;
}

std::string StringInverter::GetString() {
  return data_;
}

void StringInverter::Invert() {
  for (size_t i = 0; i < (count_-1)/2; ++i) {
    std::swap(data_[i], data_[count_-1-i]);
  }
}
