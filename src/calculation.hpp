#ifndef NUMERICAL_ANALYSIS_CALCULATION_HPP
#define NUMERICAL_ANALYSIS_CALCULATION_HPP

#include "data.hpp"

/**
 * 行列の積
 */
template<typename T, std::size_t N, std::size_t M, std::size_t L>
Mat<T, N, M> dot(const Mat<T, N, L> &a, const Mat<T, L, M> &b) {
    Mat<T, N, M> result(0);

    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < M; ++j) {
            for (std::size_t k = 0; k < L; ++k) {
                result.at(i, j) += a.at(i, k) * b.at(k, j);
            }
        }
    }
    return result;
}

template<typename T, std::size_t N, std::size_t M>
Mat<T, 1, M> dot(const Mat<T, N, M> &mat, const Mat<T, 1, M> &vec) {
    Mat<T, 1, M> result(0);

    for (std::size_t i = 0; i < N; ++i) {
        for (std::size_t j = 0; j < M; ++j) {
            result.at(0, i) += mat.at(i, j) * vec.at(0, j);
        }
    }
    return result;
}

#endif //NUMERICAL_ANALYSIS_CALCULATION_HPP

