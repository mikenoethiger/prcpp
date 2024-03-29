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

/// Space Allocation:
/// 2x the space that was needed for the source matrix will be additionally allocated.
/// This space is used to execute the full power calculation, independent of size k.
Matrix Matrix::Power(size_t k) const {
  assert(k > 1 && horizontal_ == vertical_);

  Matrix result(*this);
  Matrix intermediate(horizontal_, horizontal_);
  double* tmp;

  for (size_t i = 1; i < k; i++) {
    MultiplyIntern(this->data_, result.data_, intermediate.data_, horizontal_, horizontal_, horizontal_);
    // swap pointers
    // use data stored in intermediate as new result
    // and data stored in result as new intermediate (since deprecated)
    tmp = result.data_;
    result.data_ = intermediate.data_;
    intermediate.data_ = tmp;
  }

  return result;
}

void Matrix::MultiplyInternFast(const double* __restrict a,
                                const double* __restrict b,
                                double* __restrict res,
                                size_t a_vertical,
                                size_t b_horizontal,
                                size_t between) {
  size_t pivotA = 0;
  size_t pivotB = 0;
  size_t pivotR = 0;
  // Für jede Zeile in A, iteriere ich einmal komplett (sequentiell) durch B.
  // Dabei multipliziere ich das erste Element in der A Zeile mit allen Elementen
  // der ersten Zeile von B. Dann das zweite Element in in Zeile A mit allen
  // Elementen aus der zweiten Zeile von B. Immer so weiter, bis ich die erste
  // Zeile von A abgearbeitet habe (zu diesem Zeitpunkt bin ich am Ende von B angelangt).
  // Dann wiederhole ich den Vorgang für alle weiteren Zeilen von A.
  // Jede Multiplikation von einem Element aus A und B, wird in der resultierenden
  // Matrix an einer bestimmten Position aufsummiert. Diese ergibt sich aus:
  // - Zeile in der sich Element aus A befindet wird Zeile in res
  // - Spalte in der sich Element aus B befindet, wird Spalte in res
  for (size_t i = 0; i < a_vertical; ++i) {
    for (size_t j = 0; j < between; ++j) {
      for (size_t k = 0; k < b_horizontal; k++) {
        res[pivotR] += a[pivotA]*b[pivotB];
        pivotB++;
        pivotR++;
      }
      pivotR -= b_horizontal;
      pivotA++;
    }
    pivotB = 0; // start again at b
    pivotR += b_horizontal; // next result row
  }
}

Matrix Matrix::MultiplyFast(const Matrix& other) const {
  assert(horizontal_ == other.vertical_);
  size_t a_vertical = vertical_;
  size_t b_horizontal = other.horizontal_;
  size_t between = horizontal_;
  Matrix res(a_vertical, b_horizontal);
  res.SetAll(0);
  MultiplyInternFast(data_, other.data_, res.Data(), a_vertical, b_horizontal, between);
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
