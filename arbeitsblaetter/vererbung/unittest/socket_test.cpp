#include <catch2/catch.hpp>

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "A3/dummy_socket.cpp"
#include "A3/loopback_socket.cpp"

TEST_CASE("SocketInterface Test", "[SocketInterface]") {
  SECTION("DummySocket Create") {
    DummySocket d;
    std::string receiver;
    bool res = d.Receive(&receiver);
    CHECK(res);
    CHECK(!receiver.compare(""));
  }
  SECTION("DummySocket Send/Receive") {
    DummySocket d;
    std::string receiver;
    bool res = d.Send("something");
    CHECK(res);
    res = d.Receive(&receiver);
    CHECK(res);
    CHECK(receiver == "something"); // NOLINT
  }
  SECTION("LoopbackSocket Create") {
    LoopbackSocket l;
    bool res = l.Receive(NULL);
    CHECK_FALSE(res);
  }
  SECTION("LoopbackSocket Send/Receive") {
    LoopbackSocket l;
    bool res = l.Send("First Message");
    CHECK(res);
    res = l.Send("Second Message");
    CHECK(res);
    std::string receiver;
    res = l.Receive(&receiver);
    CHECK(res);
    CHECK(!receiver.compare("Second Message"));
    res = l.Receive(&receiver);
    CHECK(res);
    CHECK(!receiver.compare("First Message"));
    res = l.Receive(&receiver);
    CHECK(!res);
    CHECK(!receiver.compare("First Message"));
  }
  SECTION("DummySocket to LoopbackSocket cast") {
    std::unique_ptr<SocketInterface> socket;
    socket = std::make_unique<DummySocket>();
    socket->Send("1. Message");
    socket->Send("2. Message");
    std::string receiver;
    CHECK(socket->Receive(&receiver));
    CHECK(!receiver.compare("2. Message"));
    CHECK(socket->Receive(&receiver));
    CHECK(!receiver.compare("2. Message"));

    socket = std::make_unique<LoopbackSocket>();
    socket->Send("1. Message");
    socket->Send("2. Message");
    CHECK(socket->Receive(&receiver));
    CHECK(!receiver.compare("2. Message"));
    CHECK(socket->Receive(&receiver));
    CHECK(!receiver.compare("1. Message"));
  }
}
