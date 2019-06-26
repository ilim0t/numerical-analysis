#include <gtest/gtest.h>
#include "data.hpp"
#include "LU_decomposition.hpp"


TEST(LU_decomposition, L) {
    EXPECT_EQ((LU_decomposition(Mat<double, 2, 2>{{1, 2},
                                                  {3, 4}}).first),
              (Mat<double, 2, 2>{{1, 0},
                                 {3, 1}}));
}

TEST(LU_decomposition, U) {
    EXPECT_EQ((LU_decomposition(Mat<double, 2, 2>{{1, 2},
                                                  {3, 4}}).first),
              (Mat<double, 2, 2>{{1, 2},
                                 {0, -2}}));
}