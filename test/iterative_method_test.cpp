#include <gtest/gtest.h>
#include <iterative_method.hpp>
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

TEST(Iterative_Method, Jacobi_Method) {
    ASSERT_NEAR((std::get<0>(
            jacobi_method(Mat<double, 2, 2>{{3, 1},
                                            {1, 3}},
                          Mat<double, 1, 2>{{-2, 2}},
                          std::function<bool(Mat<double, 1, 2>, Mat<double, 1, 2>)>(
                                  [](Mat<double, 1, 2> x, Mat<double, 1, 2> x_pre) {
                                      return (x - x_pre).norm_2() / x.norm_2() < 1e-3;
                                  }), Mat<double, 1, 2>(0))
    ).at(0, 0)), -1, 1e-3);

    ASSERT_NEAR((std::get<0>(
            jacobi_method(Mat<double, 2, 2>{{3, 1},
                                            {1, 3}},
                          Mat<double, 1, 2>{{-2, 2}},
                          relative_error<double, 2>(1e-5), Mat<double, 1, 2>(0))
    ).at(0, 1)), 1, 1e-3);
}