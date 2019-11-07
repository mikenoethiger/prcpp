#pragma once

#include "control_block.h"
#include "item.h"

class SmartPointer {
 public:
  explicit SmartPointer(Item* p = nullptr);
  SmartPointer(const SmartPointer& sp);

  ~SmartPointer();

  SmartPointer& operator=(const SmartPointer& sp);
  SmartPointer& operator=(Item* p);

  const Item& operator*() const;
  Item* operator->() const;

  bool IsUnique() const;

 private:
  void InitControlBlock(Item* p = nullptr);
  void ReleaseControlBlock();

  ControlBlock* control_block_;
};
