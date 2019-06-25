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