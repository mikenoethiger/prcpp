#include "loopback_socket.h"
#include <iostream>

LoopbackSocket::~LoopbackSocket() {
  std::cout << "LoopbackSocker destructor" << std::endl;
}

bool LoopbackSocket::Receive(std::string* message) {
  if (deque_.size() == 0) return false;
  *message = deque_.back();
  deque_.pop_back();
  return true;
}

bool LoopbackSocket::Send(const std::string& message) {
  deque_.push_back(message);
  return true;
}
