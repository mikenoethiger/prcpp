#include <catch2/catch.hpp>

#include "d_linked_list.h"

TEST_CASE("DLinkedList Test") {
  SECTION("int list") {
    using T = int;
    DLinkedList<T> list;
    REQUIRE(list.size() == 0);

    Item<T> item1 = list.addBack(1);
    REQUIRE(item1.data_ == 1);
    list.addBack(2);
    Item<T> item2 = list.addBack(3);
    REQUIRE(list.size() == 3);

    Item<T> head = list.getHead();
    REQUIRE(head == item1);
    Item<T> tail = list.getTail();
    REQUIRE(tail == item2);

    Item<T> item3 = list.cyclicNext(head);
    item3 = list.cyclicNext(head);
    REQUIRE(item3.data_ == 3);
    item3 = list.cyclicNext(head);
    REQUIRE(item3 == head);

    item3 = list.cyclicPrevious(head);
    REQUIRE(item3 == tail);
  }
}
