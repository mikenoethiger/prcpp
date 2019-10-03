#pragma once
#include <string>

class Module {
 public:
  Module(int credits, const char* name);

  int credits_;
  std::string name_;
};