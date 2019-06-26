#ifndef NUMERICAL_ANALYSIS_MAT_UTILS_HPP
#define NUMERICAL_ANALYSIS_MAT_UTILS_HPP

#include "data.hpp"

/**
 * Matを出力するためのもの
 *
 * std::cout << Mat<float, 2, 2> {{0, 1}, {1, 2}} のように使う
 */
template<typename T, std::size_t R, std::size_t C>
std::ostream &operator<<(std::ostream &stream, const Mat<T, R, C> &mat) {
    stream << "[";
    for (std::size_t i = 0; i < mat.raw_size() - 1; ++i) {
        if (i != 0) {
            stream << " ";
        }
        stream << "[";
        std::copy(mat.begin()[i].begin(), mat.begin()[i].end() - 1, std::ostream_iterator<T>(stream, ", "));
        stream << mat.begin()[i].back() << "]," << std::endl;
    }
    stream << "[";
    std::copy(mat.back().begin(), mat.back().end() - 1, std::ostream_iterator<T>(stream, ", "));
    stream << mat.back().back() << "]]";
    return stream;
}


/**
 * Mat同士を比較するもの
 */
template<typename T, std::size_t R, std::size_t C>
inline bool operator==(const Mat<T, R, C> &a, const Mat<T, R, C> &b) {
    return a.mat_ == b.mat_;
}

template<typename T, std::size_t R, std::size_t C>
inline bool operator!=(const Mat<T, R, C> &a, const Mat<T, R, C> &b) {
    return a.mat_ != b.mat_;
}

template<typename T>
inline bool operator==(const Mat<T, 1, 1> &a, T b) {
    return a.at(0, 0) == b;
}

template<typename T>
inline bool operator!=(const Mat<T, 1, 1> &a, T b) {
    return a.at(0, 0) != b;
}

template<typename T>
inline bool operator==(T b, const Mat<T, 1, 1> a) {
    return b == a.at(0, 0);
}

template<typename T>
inline bool operator!=(T b, const Mat<T, 1, 1> &a) {
    return b != a.at(0, 0);
}

/**
 * Mat同士の演算
 */
template<typename T, std::size_t N, std::size_t M>
inline Mat<T, N, M> operator-(const Mat<T, N, M> &mat) {
    auto result = mat.copy();
    for (auto &col: result) {
        for (auto &x: col) {
            x = -x;
        }
    }

    return result;
}

#endif //NUMERICAL_ANALYSIS_MAT_UTILS_HPP
