#include "control_block.h"

ControlBlock::ControlBlock(Item* item) :
item_(item),
shared_count_(1) {}

ControlBlock::~ControlBlock() {
  delete item_;
}

void ControlBlock::increment() {
  shared_count_++;
}

void ControlBlock::decrement() {
  shared_count_--;
}

int ControlBlock::shared_count() {
  return shared_count_;
}

Item* ControlBlock::get_item() {
  return item_;
}
