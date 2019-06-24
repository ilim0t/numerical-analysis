#include <gtest/gtest.h>
#include <complex>
#include "data.hpp"

TEST(Data_Mat_Norm, Norm1) {
    EXPECT_EQ((Mat<double, 2, 3>{
            {0, 1, 2},
            {4, 8, 16}}.norm_1()), 18);

    EXPECT_EQ((Mat<std::complex<double>, 2, 3>{
            {std::complex<double>(0, 0), std::complex<double>(4, 3),  std::complex<double>(12, 5)},
            {std::complex<double>(3, 4), std::complex<double>(5, 12), std::complex<double>(8, 15)}
    }.norm_1()), 30);
}

TEST(Data_Mat_Norm, Norm_Inf) {
    EXPECT_EQ((Mat<double, 2, 3>{
            {0, 1, 2},
            {4, 8, 16}}.norm_inf()), 28);

    EXPECT_EQ((Mat<std::complex<double>, 2, 3>{
            {std::complex<double>(0, 0), std::complex<double>(4, 3),  std::complex<double>(12, 5)},
            {std::complex<double>(3, 4), std::complex<double>(5, 12), std::complex<double>(8, 15)}
    }.norm_inf()), 35);
}
