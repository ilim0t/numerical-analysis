#ifndef NUMERICAL_ANALYSIS_ITERATIVE_METHOD_HPP
#define NUMERICAL_ANALYSIS_ITERATIVE_METHOD_HPP

#include <vector>
#include <functional>
#include <tuple>

/**
 * セカント法
 *
 * @param func : 対象の方程式
 * @param convergence_codition: 収束条件
 * @param first_value: 初期値
 * @param second_value: 初期値の次の値
 * @param max_num: 最大反復回数N (x_N まで求める)
 *
 * @return std::tuple
 *          求めた解,
 *          反復した回数,
 *          最大反復回数までに収束したかどうか,
 *          解を求める求める途中での数列 (x_n)
 */
template<typename T>
std::tuple<T, std::size_t, bool, std::vector<T>>
secant(const std::function<T(T)> &func, const std::function<bool(T)> &convergence_codition, T x0 = 0,
       T x1 = 1, std::size_t max_num = 1e+10) {
    std::vector<T> xs = {x0, x1};

    if (convergence_codition(xs.back())) {
        return {xs.back(), 2, true, xs};
    }

//    反復
    for (int n = 2; n <= max_num; ++n) {
        xs.push_back(
                xs.back() -
                func(xs.back()) * (xs.back() - xs.crbegin()[1]) / (func(xs.back()) - func(xs.crbegin()[1])));

        if (convergence_codition(xs.back())) {
            return {xs.back(), n, true, xs};
        }
    }
    return {xs.back(), max_num, false, xs};
}

#endif //NUMERICAL_ANALYSIS_ITERATIVE_METHOD_HPP
