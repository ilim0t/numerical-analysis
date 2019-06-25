#include <gtest/gtest.h>
#include "iterative_method.hpp"
#include <cmath>
#include <functional>
#include <tuple>

TEST(Iterative_Method, Secant) {

    ASSERT_NEAR(std::get<0>(secant(
            std::function<double(double)>([](double x) { return x * x - 4; }),
            std::function<bool(double, double)>([](double x, double x_pre) { return std::abs(x - 2) < 1e-3; }))), 2,
                1e-3);


    ASSERT_NEAR(std::get<0>(secant(
            std::function<double(double)>([](double x) { return x * x - 4; }),
            error(1e-5))), 2, 1e-3);
}