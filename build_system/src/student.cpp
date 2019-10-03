#include <student.h>

Student::Student()
: nextModuleIndex(0)
{}
Student::~Student() {}

size_t Student::GetModuleCount() {
  return nextModuleIndex;
}

Module Student::GetModule(size_t index) {
  return *modules_[index];
}

bool Student::AddModule(Module newModule) {
  if (nextModuleIndex >= kMaxModules) {
    return false;
  }
  modules_[nextModuleIndex++] = &newModule;
  return true;
}

bool Student::RemoveModule(size_t index) {
  if (index < 0 || index >= GetModuleCount()) {
    return false;
  }
  for (int i = index; i < kMaxModules-1; i++) {
    modules_[i] = modules_[i+1];
  }
  nextModuleIndex--;
  return true;
}