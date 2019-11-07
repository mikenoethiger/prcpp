#include "bicycle.h"

#include <iostream>

#include "user.h"

Bicycle::Bicycle(std::weak_ptr<User> owner) : owner_(owner) {
  name_ = std::string("Bicycle of ") + owner_.lock()->GetName();
}

Bicycle::~Bicycle() {
  std::cout << "dtor: " << GetName() << std::endl;
}

std::string Bicycle::GetName() const {
  return name_;
}
