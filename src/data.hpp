#ifndef NUMERICAL_ANALYSIS_DATA_HPP
#define NUMERICAL_ANALYSIS_DATA_HPP

#include <array>
#include <initializer_list>
#include <functional>
#include <cassert>
#include <algorithm>
#include <iterator>
#include <ostream>
#include <complex>

template<typename T, std::size_t R, std::size_t C>
struct Mat {
    static_assert(R * C > 0, "number of matrix elements must greater than 0");
    std::array<std::array<T, C>, R> mat_;

    Mat(const std::initializer_list<std::array<T, C>> &list) {
        assert(list.size() == raw_size());
        for (std::size_t i = 0; i < list.size(); ++i) {
            mat_.at(i) = list.begin()[i];
        }
    };

    Mat(const T &init_value) {
        for (auto &col: mat_) {
            col.fill(init_value);
        }
    }

    Mat(const std::function<T(std::size_t, std::size_t)> &func) {
        for (std::size_t i = 0; i < raw_size(); ++i) {
            for (std::size_t j = 0; j < col_size(); ++j) {
                at(i, j) = func(i, j);
            }
        }
    }


    constexpr const std::size_t raw_size() const {
        return R;
    }

    constexpr const std::size_t col_size() const {
        return C;
    }

    constexpr const std::size_t size() const {
        return R * C;
    }

    T &at(std::size_t i, std::size_t j) {
        return mat_.at(i).at(j);
    }

    constexpr const T &at(std::size_t i, std::size_t j) const {
        return mat_.at(i).at(j);
    }

    std::array<T, C> *
    begin() noexcept { return mat_.begin(); }

    const std::array<T, C> *
    begin() const noexcept { return mat_.begin(); }

    std::array<T, C> *
    end() noexcept { return mat_.end(); }

    const std::array<T, C> *
    end() const noexcept { return mat_.end(); }

    std::array<T, C> &
    front() noexcept { return mat_.front(); }

    constexpr const std::array<T, C> &
    front() const noexcept { return mat_.front(); }

    std::array<T, C> &
    back() noexcept { return mat_.back(); }

    constexpr const std::array<T, C> &
    back() const noexcept { return mat_.back(); }

    Mat<T, R, C> copy() const {
        Mat<T, R, C> result(0);
        for (std::size_t i = 0; i < R; ++i) {
            result.mat_.at(i) = mat_.at(i);
        }
        return result;
    };


    const decltype(std::abs(mat_.at(0).at(0))) norm_1() const {
        std::array<decltype(std::abs(mat_.at(0).at(0))), C> each_col_sums;

        each_col_sums.fill(0);
        for (const auto &raw : mat_) {
            for (std::size_t i = 0; i < col_size(); ++i) {
                each_col_sums.at(i) += std::abs(raw.at(i));
            }
        }
        return *std::max_element(each_col_sums.begin(), each_col_sums.end());
    }

    const decltype(std::abs(mat_.at(0).at(0))) norm_inf() const {
        std::array<decltype(std::abs(mat_.at(0).at(0))), R> each_raw_sums;
        each_raw_sums.fill(0);

        for (std::size_t i = 0; i < raw_size(); ++i) {
            for (const auto &x: mat_.at(i)) {
                each_raw_sums.at(i) += std::abs(x);
            }
        }
        return *std::max_element(each_raw_sums.begin(), each_raw_sums.end());
    }
};

#include "mat_utils.hpp"
#include "calculation.hpp"

#endif //NUMERICAL_ANALYSIS_CALCULATION_HPP
