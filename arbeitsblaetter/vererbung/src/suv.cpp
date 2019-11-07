#include "suv.h"

Suv::Suv(size_t mass, double speed) :
Vehicle(mass),
speed_(speed) {}

double Suv::GetSpeed() const {
  return speed_;
}
