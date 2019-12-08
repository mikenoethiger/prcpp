#pragma once

#include "item.h"

template<typename T>
class DLinkedList {
 public:
  DLinkedList();
  ~DLinkedList();

  Item<T> getHead();
  Item<T> getTail();
  Item<T> cyclicNext(Item<T> item);
  Item<T> cyclicPrevious(Item<T> item);
  Item<T> addBack(T data);
  size_t size();

 private:
  Item<T> dummy_;
  size_t size_;
};
