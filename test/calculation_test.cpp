#include <gtest/gtest.h>
#include <complex>
#include <iostream>
#include "data.hpp"
#include "calculation.hpp"

TEST(Data_Mat_Calculation, Dot) {
    EXPECT_EQ(dot(Mat<double, 2, 2>{{1, 2},
                                    {3, 4}},
                  Mat<double, 2, 2>{{5, 6},
                                    {7, 8}}),
              (Mat<double, 2, 2>{{19, 22},
                                 {43, 50}}));

    EXPECT_EQ(dot(Mat<double, 1, 2>{{0.1, 0.4}},
                  Mat<double, 2, 1>{{0.3},
                                    {0.6}}),
              (Mat<double, 1, 1>{{0.27}}));
}