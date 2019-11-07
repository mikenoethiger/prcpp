#pragma once

#include <string>
#include <memory>

class User;

class Bicycle {
 public:
  explicit Bicycle(std::weak_ptr<User> owner);
  ~Bicycle();

  std::string GetName() const;

 private:
  std::string name_;
  std::weak_ptr<User> owner_;
};
