#include "catch2/catch.hpp"

#include "mutex_guard.h"

TEST_CASE("MutextGuard Test", "[MutexGuard]") {
  SECTION("automatically unlocked") {
    Mutex m;
    {
      m.lock();
      REQUIRE(m.locked);

      MutexGuard guard(&m);
    }
    REQUIRE(m.locked == false);
  }
}
