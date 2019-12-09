#pragma once

#include <iostream>

template<typename T>
class DLinkedList {
 public:
  class Item {
   public:
    T getData() const {
      return data_;
    }

    bool operator==(const Item& other) const {
      // compare the memory addresses
      return this == &other;
    }

    bool operator!=(const Item& other) const {
      return !(this == other);
    }

    friend std::ostream& operator<<(std::ostream& os, Item const& item) {
      os << item.data_;
      return os;
    }

    friend DLinkedList<T>;

   private:
    T data_;
    Item* next_;
    Item* prev_;
  };

  DLinkedList() : size_(0) {
    auto* dummy = allocateItem();
    dummy->next_ = dummy;
    dummy->prev_ = dummy;
    dummy_ = dummy;
  }

  ~DLinkedList() {
    Item* pivot = dummy_->next_;
    Item* tmp;
    while (pivot != dummy_) {
      tmp = pivot->next_;
      delete pivot;
      pivot = tmp;
    }
    delete dummy_;
  }

  const Item& getHead() {
    return cyclicNext(dummy());
  }
  const Item& getTail() {
    return cyclicPrevious(dummy());
  }
  const Item& cyclicNext(const Item& item) {
    auto* next = item.next_;
    if (*next == dummy()) {
      next = next->next_;
    }
    return *next;
  }
  const Item& cyclicPrevious(const Item& item) {
    auto* prev = item.prev_;
    if (*prev == dummy()) {
      prev = prev->prev_;
    }
    return *prev;
  }

  const Item& addBack(T data) {
    auto* item = allocateItem();
    item->data_ = data;
    auto* oldTail = dummy().prev_;

    dummy_->prev_ = item;
    item->next_ = dummy_;
    item->prev_ = oldTail;
    oldTail->next_ = item;

    size_++;

    return *item;
  }

  size_t size() {
    return size_;
  }

 private:
  Item& dummy() {
    return *dummy_;
  }

  Item* allocateItem() {
    auto* item = new Item();
    return item;
  }

  Item* dummy_;
  size_t size_;
};
