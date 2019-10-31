#include <iostream>
#include <sstream>
#include "set.h"
#include <cstdio>

Set::Set(size_t size) :
values_(std::make_unique<int[]>(size)),
size_(0) {
  std::cout << GetIdentifierName() << " size-ctor: allocate " << size << " elements" << std::endl;
}

Set::Set() :
Set(0) {
  std::cout << GetIdentifierName() << " default-ctor" << std::endl;
}

Set::Set(const Set& other) :
values_(other.values_),
size_(other.size_) {
  std::cout << GetIdentifierName() << " copy-ctor " << other << std::endl;
}

Set::Set(Set&& other) noexcept :
    values_(other.values_),
    size_(other.size()) {
  other.size_ = 0;
  std::cout << GetIdentifierName() << " move-ctor " << other << std::endl;
}

Set::~Set() {
  std::cout << GetIdentifierName() << " dtor" << std::endl;
}

Set::Set(const std::initializer_list<int>& list) : Set(list.size()) {
  for (const auto& val : list) {
    if (!Contains(val)) {
      AddUnchecked(val);
    }
  }
  std::cout << GetIdentifierName() << " initializer_list-ctor " << *this << std::endl;
}

int Set::AtUnchecked(size_t i) const {
  return *(begin()+i);
}

int& Set::AtUnchecked(size_t i) {
  return *(begin()+i);
}

void Set::AddUnchecked(int e) {
  *(end()) = e;
  size_++;
}

void Set::RemoveUnchecked(int e) {
  size_t i = -1;
  int* it = MoveIteratorTo(e);

  // element not found
  if (it == end()) return;

  while (it != end()-1) {
    *it = *(it+1);
    it++;
  }
  size_--;
}

int* Set::MoveIteratorTo(int e) const {
  int* it = begin();
  while (it != end() && *it != e) {
    it++;
  }
  return it;
}

bool Set::Contains(int e) const {
  int* it = MoveIteratorTo(e);
  return it != end();
}

bool Set::ContainsAll(const Set& set) const {
  for (int* i = set.begin(); i != set.end(); ++i) {
    if (!Contains(*i)) return false;
  }
  return true;
}

bool Set::operator==(const Set& set) const {
  return ContainsAll(set) && set.ContainsAll(*this);
}

bool Set::operator!=(const Set& set) const {
  return !(set == *this);
}

Set Set::Merge(const Set& other) const {
  std::cout << GetIdentifierName() << " merge " << other << " OR " << *this << std::endl;
  Set mergedSet(size()+other.size());
  for (const auto& e : *this) {
    mergedSet.AddUnchecked(e);
  }
  for (const auto& e : other) {
    if (!mergedSet.Contains(e)) {
      mergedSet.AddUnchecked(e);
    }
  }
  return mergedSet;
}

Set Set::Intersection(const Set& other) const {
  std::cout << GetIdentifierName() << " copy intersection " << other << " AND " << *this << std::endl;
  Set intersection(size());
  for (const auto& e : *this) {
    if (other.Contains(e)) {
      intersection.AddUnchecked(e);
    }
  }
  return intersection;
}

Set Set::Difference(const Set& other) const {
  std::cout << GetIdentifierName() << " copy difference " << other << " - " << *this << std::endl;
  Set difference(other.size());
  for (const auto& e : other) {
    if (!this->Contains(e)) difference.AddUnchecked(e);
  }
  return difference;
}

Set Set::Intersection(Set&& other) const {
  std::cout << GetIdentifierName() << " move intersection " << other << " AND " << *this << std::endl;
  // Check if other Set's refer to the same array on the heap, hence we should not manipulate the array.
  if (other.values_.use_count() > 1) {
    // "other" automatically decayed to lvalue when function was entered,
    // hence copy-intersection method will be called
    return Intersection(other);
  }
  // force rvalue conversion with std::move, due to automatic decay
  Set intersection(std::move(other));
  for (const auto& e : intersection) {
    if (!this->Contains(e)) {
      intersection.RemoveUnchecked(e);
    }
  }
  return intersection;
}

Set Set::Difference(Set&& other) const {
  std::cout << GetIdentifierName() << " move difference " << other << " - " << *this << std::endl;
  // Check if other Set's refer to the same array on the heap, hence we should not manipulate the array.
  if (other.values_.use_count() > 1) {
    // "other" automatically decayed to lvalue when function was entered,
    // hence copy-difference method will be called
    return Difference(other);
  }
  // force rvalue conversion with std::move, due to automatic decay
  Set difference(std::move(other));
  for (const auto& e : *this) {
    difference.RemoveUnchecked(e);
  }
  return difference;
}

std::string Set::GetIdentifierName() const {
  std::stringstream s;
  s << "Set (" << this << "):";
  return s.str();
}

void Set::RemoveDebug(int e) {
  RemoveUnchecked(e);
}
