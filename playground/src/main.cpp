#include <iostream>
#include <sstream>
#include <string>
#include <ctime>

void printAscii() {
  static constexpr size_t kColumnCount = 4;
  std::cout << "ASCII-Tabelle" << std::endl;

  for (size_t i = 32; i < 128; ++i) {
    std::cout.width(3); // Zahlenbreite: 3
    std::cout.fill('0'); // mit führenden Nullen auffüllen
    std::cout << i << " = 0x";
    std::cout.setf(std::ios::hex, std::ios::basefield); // Basis 16
    std::cout.setf(std::ios::uppercase); // Hex mit Grossbuchstaben
    std::cout << i << ": ";
    std::cout.unsetf(std::ios::hex); // wieder auf Dezimal umstellen
    std::cout << static_cast<char>(i) << '\t';

    if (i % kColumnCount == kColumnCount - 1) {
      std::cout << std::endl; // Zeilenumbruch nach 4 Spalten
    }
  }
}

void unformattedInput() {
  char c;
  char initial;
  char plz[5]; // mit Platz für Stringende

  std::cout << "Initiale: ";
  std::cin.get(initial);
  std::cin.get(c); // Return lesen

  std::cout << "Postleitzahl: ";
  //std::cin.getline(plz, 5); // liest und entfernt delimiter (\n) automatisch
  std::cin.getline(plz, 5); // liest und entfernt delimiter (\n) automatisch

  std::cout << std::endl << "You entered:" << std::endl;
  std::cout << "Initial: " << initial << std::endl;
  std::cout << "PLZ: " << plz << std::endl;
}

std::string highAndLow(const std::string& numbers) {
  std::stringstream numbers_stream(numbers);
  int x;
  numbers_stream >> x;
  int max, min = x;
  while (numbers_stream.good()) {
    numbers_stream >> x;
    if (x > max) max = x;
    if (x < min) min = x;
  }
  std::stringstream out;
  out << max << " " << min;
  return out.str();
}

void pointersAndReferences() {
  std::cout << "b references a" << std::endl;
  int a = 5;
  int &b = a;
  b = 4;
  std::cout << "a=" << a << " b=" << b << std::endl;
  a = 6;
  std::cout << "a=" << a << " b=" << b << std::endl;
  std::cout << "d points to c" << std::endl;
  int c = 7;
  int *d = &c;
  c = 8;
  std::cout << "c=" << c << " d=" << *d << std::endl;
  *d = 9;
  std::cout << "c=" << c << " d=" << *d << std::endl;
  std::cout << "d points to b, b references a" << std::endl;
  d = &b;
  a = 10;
  std::cout << "a=" << a << " b=" << b << " d=" << *d << std::endl;
  b = 11;
  std::cout << "a=" << a << " b=" << b << " d=" << *d << std::endl;
  *d = 12;
  std::cout << "a=" << a << " b=" << b << " d=" << *d << std::endl;
  std::cout << "addresses:" << std::endl;
  std::cout << "a=" << &a << " b=" << &b << " d=" << &d << std::endl;
}

void DoSomething(const std::string& text) {
  std::cout << "lvalue: " << text << std::endl;
}

void DoSomething(const std::string&& text) {
  std::cout << "rvalue: " << text << std::endl;
}

struct Father {
  virtual void Foo(char c) {
    std::cout << c << std::endl;
  }
};

struct Child : Father {
  void Foo(int i) {
    std::cout << i << std::endl;
  }
};

class Point {
 public:
  Point(int x, int y) : x_(x), y_(y) {}

  Point operator+(const Point& other) const {
    return Point(x_ + other.x_, y_ + other.y_);
  }

  friend std::ostream& operator<<(std::ostream& os, const Point& p) {
    return os << "(" << p.x_ << "," << p.y_ << ")";
  }

  const int x_;
  const int y_;
};

template<int a, int b>
struct Multiplication {
  static constexpr int value = a+b;
};

template<int a, int b>
struct Division : std::integral_constant<int, a*b> {};

struct Addition {
  static constexpr int add(int a, int b) {
    return a+b;
  }
};


template<typename number>
struct Using {
  void setX(number x) {
    x_ = x;
    std::cout << x_ << std::endl;
  }

  number x_;
};

class Tupel {
 public:
  int a;
  int b;
};

int main(int argc, char* argv[]) {
  Using<size_t> u;
  u.setX(10);
  u.setX(-149);
  u.setX(123456);
  u.setX(2.5);
  u.setX('C');

  decltype(u.x_) another_number;
  another_number =

  auto a = 1;
  auto b = "Hallo";

  Tupel t {1,2};

  return 0;
}
