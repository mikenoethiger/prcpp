#include <matrix.h>
#include <cassert>
#include <random>
#include <utils/math.h>
#include <iostream>

Matrix::Matrix(size_t vertical, size_t horizontal)
: vertical_(vertical), horizontal_(horizontal), size_(vertical*horizontal) {
  assert(vertical > 0 && horizontal > 0);
  data_ = new double[size_];
  assert(data_ != nullptr);
}

Matrix::Matrix(const Matrix& other)
: Matrix(other.vertical_, other.horizontal_) {
  data_ = new double[size_];
  for (size_t i = 0; i < size_; i++) {
    data_[i] = other.data_[i];
  }
}

Matrix::~Matrix() {
  delete[] data_;
}

size_t Matrix::Size() const {
  return size_;
}

void Matrix::SetAll(double value) {
  for (size_t i = 0; i < size_; i++) {
    data_[i] = value;
  }
}

void Matrix::SetIdentity() {
  double* row = data_;
  for (size_t m = 0; m < vertical_; ++m) {
    for (size_t n = 0; n < horizontal_; n++) {
      if (m == n) {
        row[n] = static_cast<double>(1);
      } else {
        row[n] = static_cast<double>(0);
      }
    }
    row += horizontal_;
  }
}

void Matrix::SetRandom() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0, 1.0);
  for (size_t i = 0; i < size_; i++) {
    data_[i] = dis(gen);
  }
}

bool Matrix::Equals(const Matrix& other) const {
  if (vertical_ != other.vertical_ || horizontal_ != other.horizontal_) return false;
  for (size_t i = 0; i < size_; ++i) {
    if (!Math::AlmostEquals(data_[i], other.data_[i])) return false;
  }
  return true;
}

void Matrix::MultiplyIntern(const double* a,
                            const double* b,
                            double* res,
                            size_t a_vertical,
                            size_t b_horizontal,
                            size_t between) {
  double* row = res;
  for (size_t r = 0; r < a_vertical; ++r) {
    for (size_t c = 0; c < b_horizontal; ++c) {
      double sum = 0;
      for (size_t i = 0; i < between; ++i) {
        double a_val = a[r*between+i];
        double b_val = b[c+b_horizontal*i];
        sum += a_val * b_val;
      }
      res[c] = sum;
    }
    res += b_horizontal;
  }
}

Matrix Matrix::Multiply(const Matrix& other) const {
  assert(horizontal_ == other.vertical_);
  size_t a_vertical = vertical_;
  size_t b_horizontal = other.horizontal_;
  size_t between = horizontal_;
  Matrix res(a_vertical, b_horizontal);
  MultiplyIntern(data_, other.data_, res.Data(), a_vertical, b_horizontal, between);
  return res;
}

void Matrix::Print() const {
  double* row = data_;
  for (size_t m = 0; m < vertical_; ++m) {
    for (size_t n = 0; n < horizontal_; n++) {
      std::cout << row[n] << " ";
    }
    std::cout << "\n";
    row += horizontal_;
  }
}

// TODO(mike) check how the Data methods should be implemented,
//  as there is already an implementation in the header file.
