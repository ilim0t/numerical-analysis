#include <gtest/gtest.h>
#include "data.hpp"
#include <complex>

TEST(Numerical_Analysis_TEST, Mat_Uniform_Initialization1)
{
  EXPECT_NO_THROW(({
    Mat<int, 2, 2> mat{
        {1315589499, -1752587546},
        {-1383364287, 1702426236}};
  }));
  EXPECT_NO_THROW(({
    Mat<double, 2, 2> mat = {
        {0.4895247625012986, -0.66465422872076},
        {0.16767020526566168, -0.5032942216481434}};
  }));
  EXPECT_NO_THROW(({
    Mat<std::complex<double>, 2, 2> mat{
        {std::complex<double>(0.60, -0.47), std::complex<double>(0.93, 0.94)},
        {std::complex<double>(-0.75, 0.81), std::complex<double>(-0.41, 0.71)}};
  }));

  EXPECT_NO_THROW(({
    Mat<double, 2, 2> mat(0);
  }));

  EXPECT_NO_THROW(({
    Mat<double, 2, 2> mat([](int i, int j) { return i + j; });
  }));
}

TEST(Numerical_Analysis_TEST, Mat_Uniform_Initialization2)
{
  EXPECT_EQ((Mat<int, 2, 2>{
                {-604796492, 46579223},
                {-528786740, -1231918123}}
                 .at(0)
                 .at(0)),
            -604796492);

  EXPECT_EQ((Mat<double, 2, 2>{
                {-0.4483032476602191, 0.9843756770107006},
                {0.5331887948956444, 0.9511613960693381}}
                 .at(0)
                 .at(1)),
            0.9843756770107006);

  EXPECT_EQ((Mat<std::complex<double>, 2, 2>{
                {std::complex<double>(0.42, -0.71), std::complex<double>(0.70, -0.07)},
                {std::complex<double>(-0.74, -0.89), std::complex<double>(0.75, -0.97)}}
                 .at(1)
                 .at(0)),
            std::complex<double>(-0.74, -0.89));
}

TEST(Numerical_Analysis_TEST, Mat_Uniform_Initialization3)
{
  EXPECT_EQ((Mat<int, 2, 2>(-375110534).at(0).at(0)), -375110534);
  EXPECT_EQ((Mat<int, 2, 2>([](int i, int j) { return i + j; }).at(0).at(1)), 1);
  EXPECT_EQ((Mat<double, 2, 2>([](int i, int j) { return i / (j + 1.0); }).at(1).at(1)), 0.5);
}
