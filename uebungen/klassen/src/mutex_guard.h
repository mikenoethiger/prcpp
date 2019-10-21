#pragma once

#include "mutex.h"

class MutexGuard {
 public:
  explicit MutexGuard(Mutex* mutex);
  ~MutexGuard();
 private:
  Mutex* mutex_;
};
