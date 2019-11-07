#pragma once

#include "base_interface.h"

class BaseImplementation : public virtual BaseInterface {
 public:
  int BaseMethod() override {
    return 1;
  }
};
