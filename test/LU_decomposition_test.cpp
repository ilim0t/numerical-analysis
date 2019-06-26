#include <gtest/gtest.h>
#include <data.hpp>
#include <LU_decomposition.hpp>


TEST(LU_decomposition, L) {
    EXPECT_EQ((LU_decomposition(Mat<double, 2, 2>{{1, 2},
                                                  {3, 4}}).first),
              (Mat<double, 2, 2>{{1, 0},
                                 {3, 1}}));
}

TEST(LU_decomposition, U) {
    EXPECT_EQ((LU_decomposition(Mat<double, 2, 2>{{1, 2},
                                                  {3, 4}}).second),
              (Mat<double, 2, 2>{{1, 2},
                                 {0, -2}}));
}


TEST(LU_decomposition, LU_Gaussian_Elimination) {
    EXPECT_EQ((LU_gaussian_elimination(Mat<double, 2, 2>{{1, 2},
                                                         {3, 4}},
                                       Mat<double, 1, 2>{{5, 11}})),
              (Mat<double, 1, 2>{{1, 2}}));
}