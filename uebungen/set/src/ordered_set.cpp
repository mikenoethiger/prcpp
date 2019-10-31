#include "ordered_set.h"
#include <algorithm>

OrderedSet::OrderedSet() :
OrderedSet(0) {}

OrderedSet::OrderedSet(Set&& other) :
Set(std::move(other)) {
  SortIntern();
}

OrderedSet::OrderedSet(size_t size) :
Set(size),
start_(0) {}

OrderedSet::OrderedSet(const Set& other) :
Set(other),
start_(0) {
  SortIntern();
}

OrderedSet::OrderedSet(const OrderedSet& other) :
Set(other),
start_(other.start_) {}

OrderedSet::OrderedSet(OrderedSet&& other) noexcept :
Set(std::move(other)),
start_(other.start_) {}

OrderedSet::OrderedSet(const std::initializer_list<int>& list) :
Set(list),
start_(0) {
  SortIntern();
}

void OrderedSet::SortIntern() {
  std::sort(std::begin(*this), std::end(*this));
}

size_t OrderedSet::IndexOf(int e) const {
  size_t index = 0;
  for (const auto& item : *this) {
    if (item == e) {
      return index;
    }
    index++;
  }
  return SIZE_MAX;
}

OrderedSet OrderedSet::GetSmaller(int x) const {
  // index points to first element >= x
  size_t index = 0;
  while (begin()+index < end() && *(begin()+index) < x) {
    index++;
  }
  OrderedSet output(*this);
  output.size_ = index;
  return output;
}

OrderedSet OrderedSet::GetLarger(int x) const {
  // index points to first element <= x
  size_t index = size()-1;
  while (index >= 0 && *(begin()+index) > x) {
    index--;
  }
  OrderedSet output(*this);
  output.start_ = index+1;
  output.size_ = size()-output.start_;
  return output;
}
