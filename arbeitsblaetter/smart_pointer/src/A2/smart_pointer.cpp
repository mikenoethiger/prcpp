#include "smart_pointer.h"

SmartPointer::SmartPointer(Item* p) {
  InitControlBlock(p);
}

SmartPointer::~SmartPointer() {
  ReleaseControlBlock();
}

SmartPointer::SmartPointer(const SmartPointer& sp) :
control_block_(sp.control_block_) {
  control_block_->increment();
}

bool SmartPointer::IsUnique() const {
  return control_block_ == nullptr ? false : control_block_->shared_count() == 1;
}

const Item& SmartPointer::operator*() const {
  return *control_block_->get_item();
}

Item* SmartPointer::operator->() const {
  return control_block_->get_item();
}

SmartPointer& SmartPointer::operator=(Item* p) {
  ReleaseControlBlock();
  InitControlBlock(p);
}

SmartPointer& SmartPointer::operator=(const SmartPointer& sp) {
  control_block_ = sp.control_block_;
  control_block_->increment();
}

void SmartPointer::ReleaseControlBlock() {
  if (control_block_ == nullptr) return;
  control_block_->decrement();
  if (control_block_->shared_count() == 0) {
    delete control_block_;
  }
}

void SmartPointer::InitControlBlock(Item* p) {
  if (p == nullptr) {
    control_block_ = nullptr;
  } else {
    control_block_ = new ControlBlock(p);
  }
}
