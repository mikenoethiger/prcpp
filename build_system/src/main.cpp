#include <iostream>
#include <module.h>
#include <student.h>

int main(int argc, char* argv[]) {
  Module m1(3, "LAG");
  Module m2(3, "MGLI");
  Module m3(3, "EANA");
  Student s;

  std::cout << "Module Count: " << s.GetModuleCount() << std::endl;
  bool addResult = s.AddModule(m1);
  std::cout << "Add module: " << (addResult ? "true" : "false") << std::endl;
  std::cout << "Module Count: " << s.GetModuleCount() << std::endl;
  addResult = s.AddModule(m2);
  std::cout << "Add module: " << (addResult ? "true" : "false") << std::endl;
  addResult = s.AddModule(m3);
  std::cout << "Add module: " << (addResult ? "true" : "false") << std::endl;
  std::cout << "Module Count: " << s.GetModuleCount() << std::endl;

  Module m0 = s.GetModule(0);
  std::cout << "module_[0]=" << m0.name_ << std::endl;
  std::cout << "module_[1]=" << m1.name_ << std::endl;
  std::cout << "module_[2]=" << m2.name_ << std::endl;

  bool removeResult = s.RemoveModule(2);
  std::cout << "Remove module: " << (removeResult ? "true" : "false") << std::endl;
  std::cout << "Module Count: " << s.GetModuleCount() << std::endl;

  return EXIT_SUCCESS;
}