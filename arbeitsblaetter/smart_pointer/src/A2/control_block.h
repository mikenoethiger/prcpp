#pragma once

#include "item.h"

class ControlBlock {
 public:
  explicit ControlBlock(Item* item);
  ~ControlBlock();
  void increment();
  void decrement();
  int shared_count();
  Item* get_item();

 private:
  Item* item_;
  int shared_count_;
};
