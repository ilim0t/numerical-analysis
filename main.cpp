#include "data.hpp"

#include <iostream>
#include <array>
#include <complex>

int main() {
    Mat<double, 2, 3> mat1{{1, 2, 3},
                           {4, 5, 6}};

    std::cout << mat1 << std::endl;

    Mat<int, 1, 5> mat2(0);

    std::cout << mat2 << std::endl;

    Mat<std::complex<double>, 2, 2> mat3([](int i, int j) { return std::complex<double>(i + j, i - j); });

    std::cout << mat3.at(0, 1) << std::endl;

    for (auto x: mat1) {
//        do something
    }

    return 0;
}