#pragma once

#include "base_implementation.h"
#include "extended_interface.h"

class ExtendedImplementation : public ExtendedInterface, public BaseImplementation {
 public:
  int ExtendedMethod() override {
    return 2;
  }
};
