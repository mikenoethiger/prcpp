#pragma once

class BarInterface {
 public:
  virtual ~BarInterface() = default;
  virtual void Describe() = 0;
};
