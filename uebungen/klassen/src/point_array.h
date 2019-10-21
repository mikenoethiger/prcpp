#pragma once

#include <cstddef>

#include "point.h"

class PointArray {
 public:
  PointArray();
  PointArray(Point const* const points, const size_t size);
  PointArray(const PointArray& other);
  ~PointArray();

  void Clear();
  size_t Size() const { return size_; }

  void Print() const;

  void PushBack(const Point& p);
  void Insert(const size_t pos, const Point& p);
  void Remove(const size_t pos);

  bool Get(const size_t pos, Point* p) const;
  Point* At(const size_t pos);
  const Point* At(const size_t pos) const;

 private:
  void Resize(size_t capacity);

  size_t size_;
  size_t capacity_;
  Point* points_;
};
