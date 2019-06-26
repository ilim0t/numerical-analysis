#include <gtest/gtest.h>
#include <complex>
#include <iostream>
#include <data.hpp>
#include <calculation.hpp>

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
              0.27);
}

TEST(Data_Mat_Calculation, Minus) {
    EXPECT_EQ((-Mat<double, 2, 2>{{1, 2},
                                  {3, 4}}),
              (Mat<double, 2, 2>{{-1, -2},
                                 {-3, -4}}));

    EXPECT_EQ((-Mat<double, 1, 1>{{0}}),
              0.);
}

TEST(Data_Mat_Calculation, Addition) {
    EXPECT_EQ((Mat<double, 2, 2>{{1, 2},
                                 {3, 4}} +
               Mat<double, 2, 2>{{1, 1},
                                 {2, 2}}),
              (Mat<double, 2, 2>{{2, 3},
                                 {5, 6}}));

    EXPECT_EQ((Mat<double, 1, 1>{{1}} + Mat<double, 1, 1>{{-1}}),
              0.);
}


TEST(Data_Mat_Calculation, Subtraction) {
    EXPECT_EQ((Mat<double, 2, 2>{{1, 2},
                                 {3, 4}} -
               Mat<double, 2, 2>{{1, 1},
                                 {2, 2}}),
              (Mat<double, 2, 2>{{0, 1},
                                 {1, 2}}));

    EXPECT_EQ((Mat<double, 1, 1>{{1}} - Mat<double, 1, 1>{{-1}}),
              2.);
}