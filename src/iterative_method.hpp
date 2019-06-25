#ifndef NUMERICAL_ANALYSIS_ITERATIVE_METHOD_HPP
#define NUMERICAL_ANALYSIS_ITERATIVE_METHOD_HPP

#include <vector>
#include <functional>
#include <tuple>

template<typename T>
std::tuple<T, std::size_t>
secant(const std::function<T(T)> &func, const std::function<bool(T)> &convergence_codition, T first_value = 0,
       T second_value = 1, std::size_t max_num = 1e+10) {
    std::vector<T> xs = {first_value, second_value};
    int interative_num = 2;

    for (; interative_num < max_num; ++interative_num) {
        xs.push_back(
                xs.back() -
                func(xs.back()) * (xs.back() - xs.crbegin()[1]) / (func(xs.back()) - func(xs.crbegin()[1])));
        if (convergence_codition(xs.back())) {
            return {xs.back(), interative_num};
// logのやつは将来設計
        }
    }
    return {xs.back(), interative_num};
}


#endif //NUMERICAL_ANALYSIS_ITERATIVE_METHOD_HPP
