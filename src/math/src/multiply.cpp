namespace math {

int multiply(int a, int b) { return a * b; }

} // namespace math

#ifdef MATH_ENABLE_TEST

#include <catch2/catch_test_macros.hpp>

TEST_CASE("Multiplications are computed", "[math::multiply]") {
    SECTION("Positive multiplication") { REQUIRE(math::multiply(10, 10) == 100); }

    SECTION("Negative multiplication") {
        REQUIRE(math::multiply(-1, 10) == -10);
        REQUIRE(math::multiply(-8, -10) == 80);
    }

    SECTION("Zero multiplication") {
        REQUIRE(math::multiply(10, 0) == 0);

        // Uncomment to view failure
        // REQUIRE(math::multiply(10, 0) == 10);
    }
}

#endif
