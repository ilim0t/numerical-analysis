#include <gtest/gtest.h>
#include <complex>
#include <iostream>
#include "data.hpp"
#include "calculation.hpp"

TEST(Data_Mat_Dot, 1) {
    EXPECT_EQ(dot(Mat<double, 2, 2>{{1, 2},
                                    {3, 4}},
                  Mat<double, 2, 2>{{5, 6},
                                    {7, 8}}),
              (Mat<double, 2, 2>{{19, 22},
                                 {43, 50}}));
}