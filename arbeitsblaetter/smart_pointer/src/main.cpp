#include <iostream>
#include <assert.h>

#include "A2/smart_pointer.h"

int main(int argc, char* argv[]) {
  SmartPointer s;
  assert(!s.IsUnique());
  {
    SmartPointer sp(new Item(11));
    assert(sp.IsUnique());

    s = sp;
    assert(!s.IsUnique());
    assert(!sp.IsUnique());
  }
  assert(s.IsUnique());
  std::cout << (*s).GetNumber() << std::endl;

  SmartPointer t(nullptr);
  assert(!t.IsUnique());
  t = nullptr;
  assert(!t.IsUnique());
  t = new Item(22);
  std::cout << t->GetNumber() << std::endl;
  assert(t.IsUnique());
  t->SetNumber(33);
  std::cout << t->GetNumber() << std::endl;
  t = nullptr;
  assert(!t.IsUnique());

  SmartPointer u(s);
  assert(!u.IsUnique());
  assert(!s.IsUnique());
  return 0;
}
