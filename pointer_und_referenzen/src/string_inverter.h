#pragma once

#include <string>
#include <string_view>

class StringInverter {
 public:
  explicit StringInverter(std::string_view init);
  ~StringInverter();

  std::string GetString();
  void Invert();

 private:
  char* data_;
  size_t count_;
};