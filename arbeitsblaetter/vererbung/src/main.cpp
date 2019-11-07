#include <iostream>
#include <memory>
#include "vehicle.h"
#include "suv.h"
#include "bar_tester.cpp"

int main(int argc, char* argv[]) {
  // lambda
  auto descriptor = [](BarInterface* obj) {
    obj->Describe();
  };

  std::cout << "BarTester Testing..." << std::endl;
  BarTester* obj1 = new BarTester("Declared with BarTester");
  descriptor(obj1);
  delete obj1;
  obj1 = nullptr;

  std::cout << "BarInterface Testing..." << std::endl;
  BarInterface* obj2 = new BarTester("Declared with BarInterface");
  descriptor(obj2);
  delete obj2;
  obj2 = nullptr; // a)

  std::cout << std::endl << "BarTester not defined..." << std::endl;
  descriptor(new BarTester("Not defined")); // b)

  //std::shared_ptr<Vehicle> vehicle = std::make_shared<Suv>(1200, 145);
  //std::cout << "Vehicle weighs " << vehicle->GetMass() << std::endl;
  //std::cout << "its speed is " << vehicle->GetSpeed() << std::endl;
}
