#include <catch2/catch.hpp>

#include "student.h"

TEST_CASE("Student Test", "[student]") {
   SECTION("Init with no modules") {
   Student stud;
   REQUIRE(stud.GetModuleCount() == 0);
 }