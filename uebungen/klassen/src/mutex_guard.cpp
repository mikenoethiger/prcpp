#include "mutex_guard.h"

MutexGuard::MutexGuard(Mutex* mutex) {
  mutex_ = mutex;
}

MutexGuard::~MutexGuard() {
  mutex_->unlock();
}
