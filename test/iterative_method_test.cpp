#include <gtest/gtest.h>
#include "iterative_method.hpp"
#include <cmath>
#include <functional>
#include <tuple>

TEST(Iterative_Method, Newton_Method) {
    ASSERT_NEAR(std::get<0>(newton(
            std::function<double(double)>([](double x) { return x * x - 4; }),
            std::function<double(double)>([](double x) { return 2 * x; }),
            std::function<bool(double, double)>([](double x, double x_pre) { return std::abs(x - 2) < 1e-3; }), 1.)), 2,
                1e-3);

    ASSERT_NEAR(std::get<0>(newton(
            std::function<double(double)>([](double x) { return x * x - 4; }),
            std::function<double(double)>([](double x) { return 2 * x; }),
            error(1e-5), 1.)), 2, 1e-3);
}

TEST(Iterative_Method, Secant_Method) {
    ASSERT_NEAR(std::get<0>(secant(
            std::function<double(double)>([](double x) { return x * x - 4; }),
            std::function<bool(double, double)>([](double x, double x_pre) { return std::abs(x - 2) < 1e-3; }))), 2,
                1e-3);

    ASSERT_NEAR(std::get<0>(secant(
            std::function<double(double)>([](double x) { return x * x - 4; }),
            error(1e-5))), 2, 1e-3);
}