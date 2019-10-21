#include "point_array.h"

#include "cassert"
#include "iostream"

PointArray::PointArray()
: size_(0), capacity_(0), points_(nullptr) {}

PointArray::PointArray(Point const* const points, const size_t size)
: size_(size), capacity_(size) {
  points_ = new Point[size];
  assert(points);
  for (int i = 0; i < size; ++i) {
    points_[i] = points[i];
  }
}

PointArray::PointArray(const PointArray& other)
: PointArray(other.points_, other.size_) {}

PointArray::~PointArray() {
  delete[] points_;
}

void PointArray::Print() const {
  std::cout << "[";
  for (int i = 0; i < size_-1; i++) {
    std::cout << "(" << At(i)->GetX() << "," << At(i)->GetY() << "),";
  }
  if (size_) std::cout << "(" << At(size_-1)->GetX() << "," << At(size_-1)->GetY() << ")";
  std::cout << "]";
}

const Point* PointArray::At(const size_t pos) const {
  return pos < size_ ? points_+pos : nullptr;
}

Point* PointArray::At(const size_t pos) {
  return pos < size_ ? points_+pos : nullptr;
}

void PointArray::Clear() {
  size_ = 0;
}

bool PointArray::Get(const size_t pos, Point* p) const {
  if (pos >= size_) {
    return false;
  }
  *p = points_[pos];
}

void PointArray::Insert(const size_t pos, const Point& p) {}

void PointArray::PushBack(const Point& p) {
  if (capacity_ < size_+1) {
    Resize(capacity_ + capacity_/2);
  }
  points_[size_++] = p;
}

void PointArray::Remove(const size_t pos) {}

void PointArray::Resize(size_t capacity) {}
