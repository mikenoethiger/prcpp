#pragma once

#include "base_interface.h"

class ExtendedInterface : public virtual BaseInterface {
 public:
  virtual int ExtendedMethod() = 0;
};
