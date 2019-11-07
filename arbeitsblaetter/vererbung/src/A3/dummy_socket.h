#pragma once

#include "socket_interface.h"

class DummySocket : public SocketInterface {
 public:
  DummySocket() : payload_("") {}
  ~DummySocket() override;

  bool Send(const std::string& message) override;
  bool Receive(std::string* message) override;

 private:
  std::string payload_;
};
