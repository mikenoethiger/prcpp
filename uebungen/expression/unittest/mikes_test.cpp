#include <catch2/catch.hpp>
#include <iostream>

#include "expression.h"
#include "expression_operations.h"
#include "vector_operations.h"
#include "element_operations.h"

TEST_CASE("Mikes Test") {
  SECTION("Playground") {
    std::vector a = {1, 2, 3};
    std::vector b = {1, 2, 3};
    const auto result = a * (a ** b);
    std::cout << result << std::endl;
  }
}
