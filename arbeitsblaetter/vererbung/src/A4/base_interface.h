#pragma once

class BaseInterface {
 public:
  virtual ~BaseInterface() = default;

  virtual int BaseMethod() = 0;
};
