#include "function.h"
#include "iostream"
#include "math.h"

int main(int argc, char* argv[]) {
  int m;
  std::cout << "Number of iterations: ";
  std::cin >> m;

  float pi = 0;
  for (int i = 0; i < m; i++) {
    float numerator = static_cast<float>(pow(-1.0f, i));
    pi += numerator/(2*i+1);
  }
  pi *= 4;

  std::cout << "PI approximation: " << pi << "\n";

  return EXIT_SUCCESS;
}
