#include "item.h"

#include <iostream>

Item::Item(int number) : number_(number) {
}

Item::~Item() {
  std::cout << "Item: " << number_ << " is destroyed" << std::endl;
}

int Item::GetNumber() const {
  return number_;
}

void Item::SetNumber(int number) {
  number_ = number;
}
