#include <array>
#include <functional>
#include <initializer_list>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>

template<typename T, std::size_t N, std::size_t M>
struct Mat : std::array<std::array<T, M>, N> {
//    typedef std::array<std::array<T, M>, N> super;

public:
    const std::size_t raw_size = N;
    const std::size_t col_size = M;

    Mat(std::initializer_list<std::array<T, M>> list) {
        const auto begin = list.begin();
        if (N != list.size()) {
            std::cout << "ERROR";
        }
        for (int i = 0; i < list.size(); ++i) {

            this->at(i) = begin[i];
        }
    }

    Mat(const T &init_value) {
        for (int i = 0; i < this->size(); ++i) {
            this->at(i).fill(init_value);
        }
    }

    Mat(const std::function<T(int, int)> &func) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                this->at(i).at(j) = func(i, j);
            }
        }
    };

    double norm_1() const {
        std::array<double, M> buf;
        buf.fill(0);
        for (const auto raw : *this) {
            for (int j = 0; j < this->col_size; ++j) {
                buf.at(j) += std::abs(raw.at(j));
            }
        }
        return *std::max_element(buf.begin(), buf.end());
    }

    double norm_inf() const {
        std::array<double, N> buf;
        buf.fill(0);
        for (int i = 0; i < this->raw_size; ++i) {
            for (const auto x : this->at(i)) {
                buf.at(i) += std::abs(x);
            }
        }
        return *std::max_element(buf.begin(), buf.end());
    }
};
