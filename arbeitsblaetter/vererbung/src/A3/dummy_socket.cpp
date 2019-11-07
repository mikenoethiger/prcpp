#include <iostream>
#include "dummy_socket.h"

DummySocket::~DummySocket() {
  std::cout << "DummySocket destructor" << std::endl;
}

bool DummySocket::Send(const std::string& message) {
  payload_ = message;
  return true;
}

bool DummySocket::Receive(std::string* message) {
  *message = payload_;
  return true;
}
