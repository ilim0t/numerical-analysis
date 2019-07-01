#include <gtest/gtest.h>
#include <complex>
#include <data.hpp>

TEST(Data_Mat_Definition, Initialization) {
    EXPECT_NO_THROW(({
        Mat<int, 2, 2> mat{
                {1315589499,  -1752587546},
                {-1383364287, 1702426236}};
    }));

    EXPECT_NO_THROW(({
        Mat<double, 2, 2> mat = {
                {0.4895247625012986,  -0.66465422872076},
                {0.16767020526566168, -0.5032942216481434}};
    }));

    EXPECT_NO_THROW(({
        Mat<std::complex<double>, 2, 2> mat{
                {std::complex<double>(0.60, -0.47), std::complex<double>(0.93, 0.94)},
                {std::complex<double>(-0.75, 0.81), std::complex<double>(-0.41, 0.71)}};
    }));

    EXPECT_NO_THROW(({ Mat<double, 2, 2> mat(0); }));

    EXPECT_NO_THROW(
            ({ Mat<double, 2, 2> mat([](int i, int j) { return i + j; }); }));
}

TEST(Data_Mat_Definition, Shape_Consistency) {
    EXPECT_EQ((Mat<int, 2, 3>{
            {0, 0, 0},
            {0, 0, 0}}).raw_size(), 2);

    EXPECT_EQ((Mat<int, 2, 3>{
            {0, 0, 0},
            {0, 0, 0}}).col_size(), 3);
}

TEST(Data_Mat_Definition, Invalid_Shape) {
    EXPECT_DEATH(({
        Mat<int, 1, 1> mat{{0},
                           {0}};
    }), "");

    EXPECT_DEATH(({
        Mat<int, 2, 2> mat{{0, 0}};
    }), "");
}

TEST(Data_Mat_Definition, Uniform_Initialization_Consistency) {
    EXPECT_EQ((Mat<int, 2, 2>{
            {-604796492, 46579223},
            {-528786740, -1231918123}}
            .at(0, 0)), -604796492);

    EXPECT_EQ((Mat<double, 2, 2>{
            {-0.4483032476602191, 0.9843756770107006},
            {0.5331887948956444,  0.9511613960693381}}
            .at(0, 1)), 0.9843756770107006);

    EXPECT_EQ(
            (Mat<std::complex<double>, 2, 2>{
                    {std::complex<double>(0.42, -0.71),  std::complex<double>(0.70, -0.07)},
                    {std::complex<double>(-0.74, -0.89), std::complex<double>(0.75, -0.97)}}
                    .at(1, 0)), std::complex<double>(-0.74, -0.89));
}

TEST(Data_Mat_Definition, Initialization_Consistency) {
    EXPECT_EQ((Mat<int, 2, 2>(-375110534).at(0, 0)), -375110534);

    EXPECT_EQ((Mat<int, 2, 2>([](int i, int j) { return i + j; }).at(0, 1)), 1);

    EXPECT_EQ((Mat<double, 2, 2>([](int i, int j) { return i / (j + 1.0); }).at(1, 1)), 0.5);
}


TEST(Data_Mat_Definition, RareShape1) {
    EXPECT_EQ((Mat<int, 1, 1>{{123}}.raw_size()), 1);
    EXPECT_EQ((Mat<int, 1, 1>{{123}}.col_size()), 1);

    EXPECT_EQ((Mat<int, 1, 1>{{123}}.at(0, 0)), 123);
}

TEST(Data_Mat_Definition, RareShape2) {
    EXPECT_EQ((Mat<int, 1, 2>{{0, 0}}.raw_size()), 1);
    EXPECT_EQ((Mat<int, 2, 1>{{0},
                              {0}}.raw_size()), 2);
    EXPECT_EQ((Mat<int, 1, 2>{{0, 0}}.col_size()), 2);
    EXPECT_EQ((Mat<int, 2, 1>{{0},
                              {0}}.col_size()), 1);

    EXPECT_EQ((Mat<int, 1, 2>{{100, 101}}.at(0, 0)), 100);
    EXPECT_EQ((Mat<int, 1, 2>{{200, 201}}.at(0, 1)), 201);

    EXPECT_EQ((Mat<int, 2, 1>{{300},
                              {301}}.at(0, 0)), 300);
    EXPECT_EQ((Mat<int, 2, 1>{{400},
                              {401}}.at(1, 0)), 401);
}

TEST(Data_Mat_Definition, Copy) {
    EXPECT_EQ((Mat<int, 1, 2>{{0, 0}}.copy()), (Mat<int, 1, 2>{{0, 0}}));

    EXPECT_EQ((Mat<double, 2, 2>{{1, 2},
                                 {3, 4}}.copy()),
              (Mat<double, 2, 2>{{1, 2},
                                 {3, 4}}));
}

TEST(Data_Mat_Definition, Substitution) {
    EXPECT_EQ((Mat<int, 1, 2>{{0, 0}}),
              (Mat<int, 1, 2>(Mat<int, 1, 2>{{0, 0}})));

    EXPECT_EQ((Mat<double, 2, 2>{{1, 2},
                                 {3, 4}}),
              (Mat<double, 2, 2>(Mat<double, 2, 2>{{1, 2},
                                                   {3, 4}})));

    EXPECT_EQ((Mat<std::complex<double>, 2, 2>{
            {std::complex<double>(0.60, -0.47), std::complex<double>(0.93, 0.94)},
            {std::complex<double>(-0.75, 0.81), std::complex<double>(-0.41, 0.71)}}),
              (Mat<std::complex<double>, 2, 2>(
                      Mat<std::complex<double>, 2, 2>{
                              {std::complex<double>(0.60, -0.47), std::complex<double>(0.93, 0.94)},
                              {std::complex<double>(-0.75, 0.81), std::complex<double>(-0.41, 0.71)}})));

    EXPECT_EQ((Mat<std::complex<double>, 2, 2>{{1, 2},
                                               {3, 4}}),
              (Mat<std::complex<double>, 2, 2>(
                      Mat<double, 2, 2>{{1, 2},
                                        {3, 4}})));
}