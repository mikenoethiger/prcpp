#include <catch2/catch.hpp>
#include <iostream>

#include "d_linked_list.h"

TEST_CASE("DLinkedList Test") {
  SECTION("int list") {
    REQUIRE(true);
    using T = int;
    DLinkedList<T> list;
    REQUIRE(list.size() == 0);

    auto& item1 = list.addBack(1);
    REQUIRE(item1.getData() == 1);
    list.addBack(2);
    auto& item2 = list.addBack(3);
    REQUIRE(list.size() == 3);

    auto& head = list.getHead();

    REQUIRE(head == item1);
    auto& tail = list.getTail();

    REQUIRE(tail == item2);

    auto& item3 = list.cyclicNext(head);
    auto& item4 = list.cyclicNext(item3);
    REQUIRE(item4.getData() == 3);
    auto& item5 = list.cyclicNext(item4);
    REQUIRE(item5 == head);

    auto& item6 = list.cyclicPrevious(head);
    REQUIRE(item6 == tail);
  }
}
