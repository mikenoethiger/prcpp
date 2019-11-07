#pragma once

#include <cstddef>

class Vehicle {
 public:
  explicit Vehicle(size_t mass);

  size_t GetMass() const;
  double virtual GetSpeed() const { return 2; }

 private:
  size_t mass_;
};
