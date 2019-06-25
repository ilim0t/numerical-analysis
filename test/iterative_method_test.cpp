#include <gtest/gtest.h>
#include "iterative_method.hpp"
#include <cmath>
#include <functional>
#include <tuple>

TEST(Iterative_Method, Secant) {

    ASSERT_NEAR(std::get<0>(secant(
            std::function<double(double)>([](double x) { return x * x - 4; }),
            std::function<bool(double)>([](double x) { return std::abs(x - 2) < 1e-3; }))), 2,
                1e-3);
}