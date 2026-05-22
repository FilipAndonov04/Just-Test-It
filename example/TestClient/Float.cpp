#include "Jti/Test.hpp"
#include "Jti/Assert.hpp"

constexpr float EPSILON = 1e-3;

TEST_CASE(Float, Equal) {
    ASSERT_EQUAL_FLOAT(0.003, 0.004, EPSILON, "these are not equal");
}