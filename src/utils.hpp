#ifndef NUMERICAL_ANALYSIS_UTILS_HPP
#define NUMERICAL_ANALYSIS_UTILS_HPP

#include "data.hpp"

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

template<typename T, std::size_t R, std::size_t C>
inline bool operator==(const Mat<T, R, C> &a, const Mat<T, R, C> &b) {
    return a.mat_ == b.mat_;
}

template<typename T, std::size_t R, std::size_t C>
bool operator!=(const Mat<T, R, C> &a, const Mat<T, R, C> &b) {
    return a.mat_ != b.mat_;
}

#endif //NUMERICAL_ANALYSIS_UTILS_HPP
