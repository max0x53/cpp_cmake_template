namespace math {

int add(int a, int b) { return a + b; }

} // namespace math

#ifdef MATH_ENABLE_TEST

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Additions are computed", "[math::add]") {
    SECTION("Positive addition") { REQUIRE(math::add(10, 10) == 20); }

    SECTION("Negative addition") {
        REQUIRE(math::add(-1, 10) == 9);
        REQUIRE(math::add(-8, -10) == -18);
    }

    SECTION("Zero addition") {
        REQUIRE(math::add(10, 0) == 10);

        // Uncomment to view failure
        // REQUIRE(math::add(10, 0) == 0);
    }
}

#endif
