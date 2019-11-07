#include <catch2/catch.hpp>

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "A4/extended_implementation.h"

TEST_CASE("ExtendedImplementation Test", "[ExtendedImplementation]") {
  SECTION("Inheritance") {
    ExtendedImplementation e;
    int i = e.BaseMethod();
    CHECK(i == 1); // NOLINT
    i = e.ExtendedMethod();
    CHECK(i == 2); // NOLINT
  }
}
