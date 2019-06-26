#ifndef NUMERICAL_ANALYSIS_LU_DECOMPOSITION_HPP
#define NUMERICAL_ANALYSIS_LU_DECOMPOSITION_HPP

#include <data.hpp>
#include <gaussian_elimination.hpp>
#include <utility>

template<typename T, std::size_t N>
std::pair<Mat<T, N, N>, Mat<T, N, N> > LU_decomposition(const Mat<T, N, N> &mat) {
    Mat<T, N, N> L(0);
    auto U = mat.copy();

    for (std::size_t i = 0; i < N; ++i) {
        L.at(i, i) = 1;
        for (std::size_t j = i + 1; j < N; ++j) {
            L.at(j, i) = U.at(j, i) / U.at(i, i);
            for (std::size_t k = 0; k < N - i; ++k) {
                U.at(j, N - k - 1) -= U.at(i, N - k - 1) * U.at(j, i) / U.at(i, i);
            }
        }
    }

    //    Lが下三角行列かどうかの確認
    for (std::size_t i = 0; i < N; ++i) {
        assert(L.at(i, i) == 1);
        for (std::size_t j = i + 1; j < N; ++j) {
            assert(L.at(i, j) == 0);
        }
    }
    //    Uが上三角行列かどうかの確認
    for (std::size_t i = 0; i < N; ++i) {
        assert(U.at(i, i) != 0);
        for (std::size_t j = i + 1; j < N; ++j) {
            assert(U.at(j, i) == 0);
        }
    }
    return {L, U};
}

template<typename T, std::size_t N>
Mat<T, 1, N> LU_gaussian_elimination(const Mat<T, N, N> &mat, const Mat<T, 1, N> &vec) {
    const auto LU = LU_decomposition(mat);
    const auto L = LU.first;
    const auto U = LU.second;

    const auto y = forward_erase(L, vec).second;
    const auto back_substitutioned = back_substitution(U, y);

    Mat<T, 1, N> result(0);
    for (std::size_t i = 0; i < N; ++i) {
        result.at(0, i) = back_substitutioned.second.at(0, i) / back_substitutioned.first.at(i, i);
    }
    return result;
}

#endif //NUMERICAL_ANALYSIS_LU_DECOMPOSITION_HPP
