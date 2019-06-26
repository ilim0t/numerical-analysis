#include <gtest/gtest.h>
#include <data.hpp>

TEST(Data_Mat_Comparison, equal) {
    EXPECT_EQ((Mat<int, 2, 2>{
            {0, 1},
            {4, 8}}), (Mat<int, 2, 2>{
            {0, 1},
            {4, 8}}));
}

TEST(Data_Mat_Comparison, Inequal) {
    EXPECT_NE((Mat<int, 2, 2>{
            {0, 1},
            {4, 8}}), (Mat<int, 2, 2>{
            {0, -1},
            {4, 8}}));
}

TEST(Data_Mat_Comparison, Scalar) {
    EXPECT_EQ((Mat<double, 1, 1>{
            {0}}), 0.);

    EXPECT_EQ((Mat<int, 1, 1>{
            {3}}), 3);

    EXPECT_EQ(0., (Mat<double, 1, 1>{
            {0}}));

    EXPECT_EQ(3, (Mat<int, 1, 1>{
            {3}}));
}