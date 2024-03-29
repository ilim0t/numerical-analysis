#ifndef NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_HPP
#define NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_HPP

#include <data.hpp>
#include <utility>
#include <cassert>
#include <iostream>

template<typename T, std::size_t N>
Mat<T, 1, N> gaussian_elimination(const Mat<T, N, N> &mat, const Mat<T, 1, N> &vec) {
    const auto forward_eraseded = forward_erase(mat, vec);
    const auto back_substitutioned = back_substitution(forward_eraseded.first, forward_eraseded.second);
    Mat<T, 1, N> result(0);
    for (std::size_t i = 0; i < N; ++i) {
        result.at(0, i) = back_substitutioned.second.at(0, i) / back_substitutioned.first.at(i, i);
    }
    return result;
}

template<typename T, std::size_t N>
std::pair<Mat<T, N, N>, Mat<T, 1, N>> forward_erase(const Mat<T, N, N> &mat, const Mat<T, 1, N> &vec) {
    // assert();
    Mat<T, N, N> result_mat = mat.copy();
    Mat<T, 1, N> result_vec = vec.copy();

    for (std::size_t i = 0; i < N; ++i) {
        if (result_mat.at(i, i) == 0) {
            for (std::size_t j = i + 1; j < N; ++j) {
                if (result_mat.at(j, i) != 0) {
                    result_mat.mat_.at(i).swap(result_mat.mat_.at(j));
                    std::swap(result_vec.at(0, i), result_vec.at(0, j));
                    break;
                }
            }
        }
        assert(result_mat.at(i, i) != 0);

        for (std::size_t j = i + 1; j < N; ++j) {
            result_vec.at(0, j) -= result_vec.at(0, i) * result_mat.at(j, i) / result_mat.at(i, i);
            for (std::size_t k = 0; k < N - i; ++k) {
                result_mat.at(j, N - k - 1) -= result_mat.at(i, N - k - 1) * result_mat.at(j, i) / result_mat.at(i, i);
            }
        }
    }

    // 上三角行列かどうかの確認
    for (std::size_t i = 1; i < N; ++i) {
        for (std::size_t j = 0; j < i; ++j) {
            assert(result_mat.at(i, j) == 0);
        }
    }
    return {result_mat, result_vec};
}

template<typename T, std::size_t N>
std::pair<Mat<T, N, N>, Mat<T, 1, N>> back_substitution(const Mat<T, N, N> &mat, const Mat<T, 1, N> &vec) {
    // 上三角行列かどうかの確認
    for (std::size_t i = 1; i < N; ++i) {
        for (std::size_t j = 0; j < i; ++j) {
            assert(mat.at(i, j) == 0);
        }
    }

    Mat<T, N, N> result_mat = mat.copy();
    Mat<T, 1, N> result_vec = vec.copy();

    for (std::size_t i = 0; i < N; ++i) {
        assert(result_mat.at(N - i - 1, N - i - 1) != 0);
        for (std::size_t j = i + 1; j < N; ++j) {
            result_vec.at(0, N - j - 1) -= result_vec.at(0, N - i - 1) * result_mat.at(N - j - 1, N - i - 1) /
                                           result_mat.at(N - i - 1, N - i - 1);
            result_mat.at(N - j - 1, N - i - 1) -=
                    result_mat.at(N - i - 1, N - i - 1) * result_mat.at(N - j - 1, N - i - 1) /
                    result_mat.at(N - i - 1, N - i - 1);
        }
    }
    return {result_mat, result_vec};
}

#endif //NUMERICAL_ANALYSIS_GAUSSIAN_ELIMINATION_HPP
