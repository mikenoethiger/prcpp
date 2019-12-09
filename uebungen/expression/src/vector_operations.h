#pragma once

#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
  os << "[";
  for (int i = 0; i < v.size()-1; i++) {
    os << v[i] << ",";
  }
  os << v[v.size()-1] << "]";

  return os;
}

template<typename T>
const auto* operator*(const std::vector<T>& vector) {
  return &vector;
}
