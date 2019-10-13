#include <iostream>
#include "string_inverter.h"
#include "string_inverter.cpp"

void TestMemoryManagement() {
  std::cout << "-- TestMemoryManagement --" << std::endl;
  StringInverter h("hello");
  std::cout << "original: " << h.GetString() << std::endl;
  h.Invert();
  std::cout << "inverted: " << h.GetString() << std::endl;
  std::cout << "--------------------------" << std::endl;
}

int main(int argc, char* argv[]) {
  TestMemoryManagement();
  return 0;
}
