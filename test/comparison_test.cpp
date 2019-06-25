#include <gtest/gtest.h>
#include "data.hpp"

TEST(Data_Mat_Comparison, Norm1) {
    EXPECT_EQ((Mat<int, 2, 2>{
            {0, 1},
            {4, 8}}), (Mat<int, 2, 2>{
            {0, 1},
            {4, 8}}));

    EXPECT_NE((Mat<double, 2, 2>{
            {0, 1},
            {4, 8}}), (Mat<double, 2, 2>{
            {0, -1},
            {4, 8}}));

    //誤差あり
}