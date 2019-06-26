#include <gtest/gtest.h>
#include "data.hpp"

TEST(Data_Mat_Comparison, equal) {
    EXPECT_EQ((Mat<int, 2, 2>{
            {0, 1},
            {4, 8}}), (Mat<int, 2, 2>{
            {0, 1},
            {4, 8}}));
}

TEST(Data_Mat_Comparison, Inequal) {
    EXPECT_NE((Mat<double, 2, 2>{
            {0, 1},
            {4, 8}}), (Mat<double, 2, 2>{
            {0, -1},
            {4, 8}}));
}