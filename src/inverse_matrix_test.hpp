#ifndef NUMERICAL_ANALYSIS_INVERSE_MATRIX_TEST_HPP
#define NUMERICAL_ANALYSIS_INVERSE_MATRIX_TEST_HPP

#include <data.hpp>
#include <cassert>
#include <gaussian_elimination.hpp>
#include <LU_decomposition.hpp>

template<typename T, std::size_t N>
Mat<T, N, N> inverse(const Mat<T, N, N> &mat) {
    Mat<T, N, N> result(0);
    const auto LU = LU_decomposition(mat);
    const auto L = LU.first;
    const auto U = LU.second;

    for (std::size_t i = 0; i < N; ++i) {
        Mat<T, 1, N> e(0);
        e.at(0, i) = 1;

        const auto y = forward_substitution(L, e);
        const auto x = backward_substitution(U, y);

        for (std::size_t j = 0; j < N; ++j) {
            result.at(j, i) = x.at(0, j);
        }
    }
    return result;
}

template<typename T, std::size_t N>
Mat<T, 1, N> forward_substitution(const Mat<T, N, N> &L, const Mat<T, 1, N> &e) {
//    Lが下三角行列かどうかの確認
    for (std::size_t i = 0; i < N; ++i) {
        assert(L.at(i, i) != 0);
        for (std::size_t j = i + 1; j < N; ++j) {
            assert(L.at(i, j) == 0);
        }
    }

//    eが正常な値を持っているかの確認
    bool have_one = false;
    for (std::size_t i = 0; i < N; ++i) {
        if (e.at(0, i) == 1) {
            have_one = true;
            break;
        }
        assert(e.at(0, i) == 0);
    }
    assert(have_one);

    const auto forward_eraseed = forward_erase(L, e);

    Mat<T, 1, N> result(0);
    for (std::size_t i = 0; i < N; ++i) {
        assert(forward_eraseed.first.at(i, i) != 0);
        result.at(0, i) = forward_eraseed.second.at(0, i) / forward_eraseed.first.at(i, i);
    }
    return result;
}

template<typename T, std::size_t N>
Mat<T, 1, N> backward_substitution(const Mat<T, N, N> &U, const Mat<T, 1, N> &y) {
//    Uが上三角行列かどうかの確認
    for (std::size_t i = 0; i < N; ++i) {
        assert(U.at(i, i) != 0);
        for (std::size_t j = i + 1; j < N; ++j) {
            assert(U.at(j, i) == 0);
        }
    }

    const auto back_substitutioned = back_substitution(U, y);

    Mat<T, 1, N> result(0);

    for (std::size_t i = 0; i < N; ++i) {
        assert(back_substitutioned.first.at(i, i) != 0);
        result.at(0, i) = back_substitutioned.second.at(0, i) / back_substitutioned.first.at(i, i);
    }
    return result;
}

#endif //NUMERICAL_ANALYSIS_INVERSE_MATRIX_TEST_HPP
