#pragma once

#include <string>
#include <memory>
#include <unordered_set>

#include "bicycle.h"

class User {
 public:
  explicit User(const std::string& name);
  ~User();

  std::string GetName() const;
  void UseBicycle(std::shared_ptr<Bicycle> bicycle);
  void PrintUsage() const;

 private:
  const std::string name_;
  std::unordered_set<std::shared_ptr<Bicycle>> used_bicycles_;
};
