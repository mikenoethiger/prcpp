#pragma once

struct Mutex {
  void lock() {
    locked = true;
  }
  void unlock() {
    locked = false;
  }
  bool locked;
};
