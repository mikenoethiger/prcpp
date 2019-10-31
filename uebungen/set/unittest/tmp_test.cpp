#include <catch2/catch.hpp>

#include <iostream>
#include "set.h"
#include "ordered_set.h"

TEST_CASE("Playground Test", "[Set]") {
  SECTION("single value") {
    OrderedSet single = {100};
    REQUIRE(single.GetLarger(1) == single);
  }
}
