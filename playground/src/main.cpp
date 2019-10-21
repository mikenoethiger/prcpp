#include <iostream>

int main(int argc, char* argv[]) {
  int i = 5;
  int* j = &i;

  std::cout << "i= " << i << "\n";
  std::cout << "&i= " << &i << "\n";
  std::cout << "j= " << j << "\n";
  std::cout << "*j= " << *j << "\n";
  std::cout << "&j= " << &j << "\n";
  std::cout << "&(*j)= " << &(*j) << "\n";

  return 0;
}
