#pragma once

class Point {
 public:
  explicit Point(int x = 0, int y = 0) {
    x_ = x;
    y_ = y;
  }

  int GetX() const { return x_; }
  int GetY() const { return y_; }

  void SetX(const int x) { x_ = x; }
  void SetY(const int y) { y_ = y; }

 private:
  int x_;
  int y_;
};
