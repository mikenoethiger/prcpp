#pragma once

#include <cstddef>

#include "vehicle.h"

class Suv : public Vehicle {
 public:
  Suv(size_t mass, double speed);

  double GetSpeed() const override;

 private:
  double speed_;
};
