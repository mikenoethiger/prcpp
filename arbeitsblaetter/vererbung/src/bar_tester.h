#pragma once

#include <string>

#include "bar_interface.h"

class BarTester : public BarInterface {
 public:
  explicit BarTester(const std::string& name);
  ~BarTester();

  void Describe();

 private:
  std::string private_name_;
};
