#include <catch2/catch.hpp>

#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <vector>

#include "utils/stopwatch.h"
#include "utils/chrono_io.h"
#include "matrix.h"

static void CheckContent(const Matrix& m, std::vector<double> expected) {
  CHECK(m.Size() == expected.size());
  for (size_t i = 0; i < expected.size(); ++i) {
    INFO("CheckContent [i=" << i << "]: value=" << m.Data()[i] << " expected=" << expected[i]);
    CHECK(m.Data()[i] == Approx(expected[i]));
  }
}

static void FillWithContent(const std::vector<double>& content, Matrix* matrix) {
  REQUIRE(matrix->Size() == content.size());
  std::copy(content.begin(), content.end(), matrix->Data());
}

TEST_CASE("Mikes Test", "[Matrix]") {
  const size_t d1 = 2;
  const size_t d2 = 2;
  const auto size = d1 * d2;

  SECTION("SetAll") {
    SECTION("Set all to 0.0") {
      std::vector<double> expected(size, 0);
      Matrix m1(1, 2);
      Matrix m2(2, 4);
      m1.SetAll(1);
      m2.SetAll(2);
      m1.Print();
      m2.Print();
      Matrix m3 = m1.Multiply(m2);
      m3.Print();
    }
  }
}
