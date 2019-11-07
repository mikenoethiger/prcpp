#pragma once

#include <deque>
#include "socket_interface.h"

class LoopbackSocket : public SocketInterface {
 public:
  ~LoopbackSocket() override;

  bool Send(const std::string& message) override;
  bool Receive(std::string* message) override;

 private:
  std::deque<std::string> deque_;
};
