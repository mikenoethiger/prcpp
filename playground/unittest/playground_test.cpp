#include <catch2/catch.hpp>

#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>

TEST_CASE("Playground Test", "[Playground]") {
  const size_t d1 = 2;
  const size_t d2 = 2;
  const auto size = d1 * d2;

  SECTION("#1") {
    int a[] = {1, 2, 3, 4, 5, 6};
    size_t size = 6;
    int* end = a+size;
    int* it = a;
    int e = 7;

    while (*it != e && it != end) {
      it++;
    }

    REQUIRE(it == end);

    std::cout << "Hallo Welt\n";
  }
}
