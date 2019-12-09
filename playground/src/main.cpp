#include <iostream>
#include <string>

struct Expression {
  int a_;
};

Expression* operator*(const Expression& expr) {
  Expression* dup = new Expression(expr);
  return dup;
}

auto operator*(const Expression& left, const Expression& right) {
  return left.a_ * right.a_;
}

auto operator*(const Expression& left, const Expression* right) {
  return left.a_ + right->a_;
}

int main(int argc, char* argv[]) {
  Expression exp1 {10};
  Expression exp2 {2};
  int res1 = exp1 * exp2;
  std::cout << res1 << std::endl;
  int res2 = exp1 ** exp2;
  std::cout << res2 << std::endl;

  return 0;
}
