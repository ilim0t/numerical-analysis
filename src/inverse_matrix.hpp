#ifndef NUMERICAL_ANALYSIS_INVERSE_MATRIX_HPP
#define NUMERICAL_ANALYSIS_INVERSE_MATRIX_HPP

#include <data.hpp>
#include <cassert>
#include <gaussian_elimination.hpp>

//template  <typename T, std::size_t N>
//Mat<T, N, N> inverse(const Mat<T, N, N> & mat) {
//    auto result  = mat.copy();
//
//    return result;
//}

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
    return forward_eraseed.second;
}

//template<typename T, std::size_t N>
//Mat<T, 1, N> backward_substitution(const Mat<T, N, N> &U, const Mat<T, 1, N> &y) {
//
//}

#endif //NUMERICAL_ANALYSIS_INVERSE_MATRIX_HPP
