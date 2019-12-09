#pragma once

#include <vector>
#include "element_operations.h"

template<typename Left, typename Right>
auto operator+(const Left& lhs, const Right& rhs) {
  return Expression<Left, Add, Right>(lhs, rhs);
}

template<typename Left, typename Right>
auto operator-(const Left& lhs, const Right& rhs) {
  return Expression<Left, Sub, Right>(lhs, rhs);
}

template<typename Left, typename Right>
auto operator*(const Left& lhs, const Right* rhs) {
  return Expression<Left, Dot, Right>(lhs, *rhs);
}

template<typename Left, typename Right>
auto operator*(const Left& lhs, const Right& rhs) {
  return Expression<Left, Mul, Right>(lhs, rhs);
}

template<typename Left, typename Right>
auto operator/(const Left& lhs, const Right& rhs) {
  return Expression<Left, Div, Right>(lhs, rhs);
}

template<typename L1, typename Op1, typename R1, typename L2, typename Op2, typename R2>
bool operator==(const Expression<L1, Op1, R1>& e1, const Expression<L2, Op2, R2>& e2) {
  if (e1.size() != e2.size()) return false;
  for (int i = 0; i < e1.size(); i++) {
    if (e1[i] != e2[i]) return false;
  }
  return true;
}

template<typename L, typename Op, typename R, typename T>
bool operator==(const Expression<L, Op, R>& e, const std::vector<T>& v) {
  if (e.size() != v.size()) return false;
  for (int i = 0; i < e.size(); i++) {
    if (e[i] != v[i]) return false;
  }
  return true;
}

template<typename L, typename Op, typename R, typename T>
bool operator==(const std::vector<T>& v, const Expression<L, Op, R>& e) {
  return e == v;
}

template<typename L, typename Op, typename R>
std::ostream& operator<<(std::ostream& os, const Expression<L, Op, R>& e) {
  os << "[";
  for (int i = 0; i < e.size()-1; i++) {
    os << e[i] << ",";
  }
  os << e[e.size()-1] << "]";

  return os;
}

template<typename L, typename Op, typename R>
const auto* operator*(const Expression<L, Op, R>& expr) {
  return &expr;
}
