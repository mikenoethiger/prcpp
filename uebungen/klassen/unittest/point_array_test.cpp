#include "catch2/catch.hpp"
#include "iostream"
#include "point_array.h"

static bool CheckPointAtPosition(const PointArray& array, size_t pos, const Point& point) {
  return (array.At(pos)->GetX() == point.GetX()
      && array.At(pos)->GetY() == point.GetY());
}

TEST_CASE("PointArray Tests", "[PointArray]") {
  Point p1(1, 2);
  Point p2(2, 3);
  Point p3(3, 4);
  Point p4(4, 5);

  static constexpr size_t kArraySize = 4;
  Point points[kArraySize] = {p1, p2, p3, p4};

  SECTION("Constructors") {
    PointArray pa1;
    PointArray pa2(points, kArraySize);
    PointArray pa3(pa2);

    REQUIRE(pa1.Size() == 0);
    REQUIRE(pa2.Size() == kArraySize);
    REQUIRE(pa3.Size() == kArraySize);
  }
  SECTION("Clear") {
    PointArray pa(points, kArraySize);
    pa.Clear();
    REQUIRE(pa.Size() == 0);
  }
  SECTION("Push Back") {
    PointArray pa(points, kArraySize);
    Point p = Point(5, 6);
    Point p2 = Point(6, 7);
    pa.PushBack(p);
    pa.PushBack(p2);
    pa.Print();
    REQUIRE(pa.Size() == kArraySize + 2);
    REQUIRE(CheckPointAtPosition(pa, kArraySize, p));
  }
  /*SECTION("Clear") {
    pa2.Clear();

    std::cout << "size unittest" << std::endl;
    std::cout << std::boolalpha << (pa1.Size() == 0) << std::endl;
    std::cout << std::boolalpha << (pa2.Size() == 0) << std::endl;
    std::cout << std::boolalpha << (pa3.Size() == 4) << std::endl;

    std::cout << "push-back unittest" << std::endl;
    pa3.PushBack(Point(5, 6));
    pa3.Print();

    std::cout << "remove unittest" << std::endl;
    pa3.Remove(5);
    pa3.Remove(4);
    pa3.Remove(0);
    pa3.Remove(1);
    pa3.Print();

    std::cout << "insert unittest" << std::endl;
    pa3.Insert(0, p1);
    pa3.Insert(2, p3);
    pa3.Insert(4, Point(5, 6));
    pa3.Print();
  }*/
}
