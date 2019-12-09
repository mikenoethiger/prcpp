#pragma once

#define ELEMENT_OPERATIONS_DOT

struct Add {
  template<typename T>
  static T Apply(T lhs, T rhs) {
    return lhs + rhs;
  }
};

struct Sub {
  template<typename T>
  static T Apply(T lhs, T rhs) {
    return lhs - rhs;
  }
};

struct Mul {
  template<typename T>
  static T Apply(T lhs, T rhs) {
    return lhs * rhs;
  }
};

struct Div {
  template<typename T>
  static T Apply(T lhs, T rhs) {
    return lhs / rhs;
  }
};

struct Dot {
  template<typename Left, typename Right>
  static typename Left::value_type DotApply(Left l, Right r) {
    assert(l.size() == r.size());
    using value_type = typename Left::value_type;
    value_type scalar = 0;
    for (int i = 0; i < l.size(); i++) {
      scalar += l[i] * r[i];
    }
    return scalar;
  }
};
