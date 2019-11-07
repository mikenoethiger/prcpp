#pragma once

#include <cstddef>

#include <vector>
#include <string>

class PGM {
 public:
  bool ReadASCII(const std::string& filename);
  bool WriteBinary(const std::string& filename);

 private:
  size_t width_;
  size_t height_;
  int32_t max_value_;
  std::vector<uint8_t> data_;
};