#include "bar_tester.h"

#include <iostream>

BarTester::BarTester(const std::string& name) : private_name_(name) {
  std::cout << "BarTester constructor" << std::endl;
}

BarTester::~BarTester() {
  std::cout << "BarTester destructor" << std::endl;
}

void BarTester::Describe() {
  std::cout << "I'm BarTester [" << private_name_ << "]" << std::endl;
}
