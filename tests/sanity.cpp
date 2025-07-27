#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>

int sum(int x, int y) { return x + y; }

TEST_CASE("Sanity sum test", "[catch]") {

  REQUIRE(sum(1, 1) == 2);
  REQUIRE(sum(2, 2) == 4);
}