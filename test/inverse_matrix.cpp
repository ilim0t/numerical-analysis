#include <gtest/gtest.h>
#include "data.hpp"
#include "inverse_matrix.hpp"

TEST(Mat_Inverse, Forward_Substitution) {
    ASSERT_EQ((forward_substitution(Mat<double, 2, 2>{{1, 0},
                                                      {3, 1}},
                                    Mat<double, 1, 2>{{1, 0}})),
              (Mat<double, 1, 2>{{1, -3}}));
}