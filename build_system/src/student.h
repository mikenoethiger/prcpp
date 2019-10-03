#pragma once
#include <module.h>

class Student {
 public:
  Student();
  ~Student();

  size_t GetModuleCount();
  Module GetModule(size_t index);
  bool AddModule(Module newModule);
  bool RemoveModule(size_t index);

 private:
  static constexpr size_t kMaxModules = 4;
  Module *modules_[kMaxModules];
  size_t nextModuleIndex;
};