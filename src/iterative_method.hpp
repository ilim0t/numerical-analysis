#ifndef NUMERICAL_ANALYSIS_ITERATIVE_METHOD_HPP
#define NUMERICAL_ANALYSIS_ITERATIVE_METHOD_HPP

#include <vector>
#include <functional>
#include <tuple>
#include <cmath>

//decltype(std::abs(mat_.at(0).at(0)))
template<typename T>
std::function<bool(T, T)> error(T eps = 1e-5) {
    return [&](T x, T x_pre) { return std::abs(x - x_pre) < eps; };
}

template<typename T>
std::function<bool(T, T)> relative_error(T eps = 1e-5) {
    return [&](T x, T x_pre) { return std::abs((x - x_pre) / x) < eps; };
}

template<typename T>
std::function<bool(T, T)> residual(const std::function<T(T)> &func, T eps = 1e-5) {
    return [&](T x, T x_pre) { return std::abs(func(x)) < eps; };

}


/**
 * ニュートン法
 *
 * @param func : 対象の関数
 * @param dfunc : 対象の関数を微分下関数
 * @param convergence_codition: 収束条件
 * @param first_value: 初期値
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
newton(const std::function<T(T)> &func, const std::function<T(T)> &dfunc,
       const std::function<bool(T, T)> &convergence_codition, T x0 = 0, std::size_t max_num = 1e+10) {
    std::vector<T> xs = {x0};

//    if (convergence_codition(xs.back(), xs.crbegin()[1])) {
//        return {xs.back(), 2, true, xs};
//    }

//    反復
    while (xs.size() < max_num) {
        xs.push_back(xs.back() - func(xs.back()) / dfunc(xs.back()));
        assert(!std::isinf(xs.back()));

        if (convergence_codition(xs.back(), xs.crbegin()[1])) {
            return {xs.back(), xs.size() - 1, true, xs};
        }
    }
    return {xs.back(), max_num, false, xs};
}

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
secant(const std::function<T(T)> &func, const std::function<bool(T, T)> &convergence_codition, T x0 = 0,
       T x1 = 1, std::size_t max_num = 1e+10) {
    std::vector<T> xs = {x0, x1};

    if (convergence_codition(xs.back(), xs.crbegin()[1])) {
        return {xs.back(), 2, true, xs};
    }

//    反復
    while (xs.size() < max_num) {
        xs.push_back(
                xs.back() -
                func(xs.back()) * (xs.back() - xs.crbegin()[1]) / (func(xs.back()) - func(xs.crbegin()[1])));
        assert(!std::isinf(xs.back()));

        if (convergence_codition(xs.back(), xs.crbegin()[1])) {
            return {xs.back(), xs.size() - 1, true, xs};
        }
    }
    return {xs.back(), max_num, false, xs};
}

#endif //NUMERICAL_ANALYSIS_ITERATIVE_METHOD_HPP
