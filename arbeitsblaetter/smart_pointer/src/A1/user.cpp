#include "user.h"

#include <iostream>

User::User(const std::string& name) : name_(name) {
}

User::~User() {
  std::cout << "dtor: " << GetName() << std::endl;
  PrintUsage();
}

std::string User::GetName() const {
  return name_;
}

void User::UseBicycle(std::shared_ptr<Bicycle> bicycle) {
  used_bicycles_.emplace(bicycle);
}

void User::PrintUsage() const {
  std::cout << "Bicycle usage of: " << name_ << std::endl;
  for (const auto& bicycle : used_bicycles_) {
    std::cout << " " << bicycle->GetName() << std::endl;
  }
}
