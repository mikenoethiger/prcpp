#include <catch2/catch.hpp>

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "A1/user.h"
#include "A1/bicycle.h"

TEST_CASE("BicycleUser Test", "[BicycleUser]") {
  SECTION("Section 1") {
    std::shared_ptr<User> manuel = std::make_shared<User>("manuel");
    std::shared_ptr<User> fabien = std::make_shared<User>("fabien");
    std::shared_ptr<User> stefan = std::make_shared<User>("stefan");
    std::shared_ptr<Bicycle> stefans_bicycle = std::make_shared<Bicycle>(stefan);
    std::shared_ptr<Bicycle> fabiens_bicycle = std::make_shared<Bicycle>(fabien);
    stefan->UseBicycle(stefans_bicycle);
    stefan->UseBicycle(fabiens_bicycle);
    fabien->UseBicycle(fabiens_bicycle);
    manuel->UseBicycle(stefans_bicycle);
    manuel->UseBicycle(fabiens_bicycle);
    //user->PrintUsage();
  }
}
