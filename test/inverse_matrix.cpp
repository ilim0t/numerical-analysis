#include <gtest/gtest.h>
#include "data.hpp"
#include "inverse_matrix.hpp"

TEST(Mat_Inverse, Forward_Substitution) {
    ASSERT_EQ((forward_substitution(Mat<double, 2, 2>{{1, 0},
                                                      {3, 1}},
                                    Mat<double, 1, 2>{{1, 0}})),
              (Mat<double, 1, 2>{{1, -3}}));
}

TEST(Mat_Inverse, Backward_Substitution) {
    ASSERT_EQ((backward_substitution(Mat<double, 2, 2>{{1, 2},
                                                       {0, -2}},
                                     Mat<double, 1, 2>{{1, -3}})),
              (Mat<double, 1, 2>{{-2, 3. / 2}}));
}

TEST(Mat_Inverse, Mat_Inverse) {
    ASSERT_EQ((inverse(Mat<double, 2, 2>{{1, 2},
                                         {3, 4}})),
              (Mat<double, 2, 2>{{-2,     1},
                                 {3. / 2, -1. / 2}}));
}