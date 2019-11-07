#include "vehicle.h"

Vehicle::Vehicle(size_t mass) :
mass_(mass) {}

size_t Vehicle::GetMass() const {
  return mass_;
}
