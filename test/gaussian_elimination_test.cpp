#include <gtest/gtest.h>
#include "data.hpp"
#include "gaussian_elimination.hpp"

TEST(Mat_Gauusian_Elimination_Test, Forward_Erase) {
    ASSERT_EQ((forward_erase(Mat<double, 2, 2>{{1, 4},
                                               {2, 3}},
                             Mat<double, 1, 2>{{9, 8}}).first),
              (Mat<double, 2, 2>{{1, 4},
                                 {0, -5}}));

    ASSERT_EQ((forward_erase(Mat<double, 2, 2>{{1, 4},
                                               {2, 3}},
                             Mat<double, 1, 2>{{9, 8}}).second),
              (Mat<double, 1, 2>{{9, -10}}));
}

TEST(Mat_Gauusian_Elimination_Test, Back_Substitution) {
    ASSERT_EQ((back_substitution(Mat<double, 2, 2>{{1, 4},
                                                   {0, -5}},
                                 Mat<double, 1, 2>{{9, -10}}).first),
              (Mat<double, 2, 2>{{1, 0},
                                 {0, -5}}));

    ASSERT_EQ((back_substitution(Mat<double, 2, 2>{{1, 4},
                                                   {0, -5}},
                                 Mat<double, 1, 2>{{9, -10}}).second),
              (Mat<double, 1, 2>{{1, -10}}));
}

TEST(Mat_Gauusian_Elimination_Test, Gaussian_Elimination) {
    ASSERT_EQ((gaussian_elimination(Mat<double, 2, 2>{{1, 4},
                                                      {0, -5}},
                                    Mat<double, 1, 2>{{9, -10}})),
              (Mat<double, 1, 2>{{1, 2}}));
}

TEST(Mat_Gauusian_Elimination_Test, Sparse_Gaussian_Elimination) {
    ASSERT_EQ((gaussian_elimination(Mat<double, 2, 2>{{0, 2},
                                                      {2, 3}},
                                    Mat<double, 1, 2>{{-6, -5}})),
              (Mat<double, 1, 2>{{2, -3}}));

    ASSERT_EQ((gaussian_elimination(Mat<double, 3, 3>{{0, 1, 4},
                                                      {2, 0, 3},
                                                      {2, 3, 0}},
                                    Mat<double, 1, 3>{{14, 11, 8}})),
              (Mat<double, 1, 3>{{1, 2, 3}}));
}