#pragma once

#include <string>

class SocketInterface {
 public:
  virtual ~SocketInterface() = default;

  virtual bool Send(const std::string& message) = 0;
  virtual bool Receive(std::string* message) = 0;
};
