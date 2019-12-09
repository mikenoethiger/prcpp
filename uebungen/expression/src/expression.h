#pragma once

#include <assert.h>
#include "element_operations.h"

#define EXPRESSION_BASE
#define SCALAR_FROM_LEFT
#define SCALAR_FROM_RIGHT
#define DOT_PRODUCT

template<typename Left, typename Op, typename Right>
class Expression {
 public:
  using value_type = typename Left::value_type;
  Expression(const Left& lhs, const Right& rhs) : lhs_{lhs}, rhs_{rhs} {
    assert(lhs_.size() == rhs_.size() || lhs_.size() == 1 || rhs_.size() == 1);
  }

  size_t size() const {
    return std::max(lhs_.size(), rhs_.size());
  }

  value_type operator[](size_t i) const {
    return Op::Apply(lhs_[i], rhs_[i]);
  }

  operator value_type() const {
    return Op::Apply(
        static_cast<value_type>(lhs_),
        static_cast<value_type>(rhs_));
  }

 private:
  const Left lhs_;
  const Right rhs_;
};

template<typename Op, typename Right>
class Expression<typename Right::value_type, Op, Right> {
 public:
  using value_type = typename Right::value_type;
  Expression(const value_type& lhs, const Right& rhs) : lhs_{lhs}, rhs_{rhs} {
    //assert(lhs_.size() == rhs_.size() || lhs_.size() == 1 || rhs_.size() == 1);
  }

  size_t size() const {
    return rhs_.size();
  }

  value_type operator[](size_t i) const {
    return Op::Apply(lhs_, rhs_[i]);
  }

  operator value_type() const {
    return Op::Apply(lhs_, static_cast<value_type>(
        rhs_));
  }

 private:
  const value_type lhs_;
  const Right rhs_;
};

template<typename Left, typename Op>
class Expression<Left, Op, typename Left::value_type> {
 public:
  using value_type = typename Left::value_type;
  Expression(const Left& lhs, const value_type& rhs) : lhs_{lhs}, rhs_{rhs} {
    //assert(lhs_.size() == rhs_.size() || lhs_.size() == 1 || rhs_.size() == 1);
  }

  size_t size() const {
    return lhs_.size();
  }
  value_type operator[](size_t i) const {
    return Op::Apply(lhs_[i], rhs_);
  }

  operator value_type() const {
    return Op::Apply(static_cast<value_type>(lhs_),
                     rhs_);
  }

 private:
  const Left lhs_;
  const value_type rhs_;
};

template<typename Left, typename Right>
class Expression<Left, Dot, Right> {
 public:
  using value_type = typename Left::value_type;
  Expression(const Left& lhs, const Right& rhs) : lhs_{lhs}, rhs_{rhs} {
    assert(lhs_.size() == rhs_.size() || lhs_.size() == 1 || rhs_.size() == 1);
  }

  size_t size() const {
    return 1;
  }
  value_type operator[](size_t i) const {
    return Dot::DotApply(lhs_, rhs_);
  }

  operator value_type() const {
    return Dot::DotApply(lhs_,
                         rhs_);
  }

 private:
  const Left lhs_;
  const Right rhs_;
};
