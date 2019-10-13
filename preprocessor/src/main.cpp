#include "iostream"

#define MAX(a, b) ((a) < (b) ? (b) : (a))

int max(int a, int b) {
  return a < b ? b : a;
}

void makro() {
  int x = 5, y = 10;
  int z = max(x++, y++); // max
  //int z = MAX(x++, y++); // makro
  std::cout << "x=" << x << std::endl;
  std::cout << "y=" << y << std::endl;
  std::cout << "z=" << z << std::endl;
}

void memoryUsage() {
  std::cout << "bool:\t" << sizeof(bool) << " Byte" << std::endl;
  std::cout << "short:\t" << sizeof(short) << " Byte" << std::endl;
  std::cout << "int:\t" << sizeof(int) << " Byte" << std::endl;
  std::cout << "long:\t" << sizeof(long) << " Byte" << std::endl;
  std::cout << "float:\t" << sizeof(float) << " Byte" << std::endl;
  std::cout << "double:\t" << sizeof(double) << " Byte" << std::endl;
}

int main(int argc, char* argv[]) {
  //makro();
  //memoryUsage();
  int a = 1;
  int b = 2;
  a = b = 3;
  std::cout << "a: " << a;
  std::cout << "b: " << b;

  return EXIT_SUCCESS;
}