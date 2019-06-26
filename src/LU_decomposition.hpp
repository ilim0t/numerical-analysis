//
// Created by oO0adeliae0Oo on 2019-06-26.
//
#ifndef NUMERICAL_ANALYSIS_LU_DECOMPOSITION_HPP
#define NUMERICAL_ANALYSIS_LU_DECOMPOSITION_HPP

#include <iostream>
#include <utility>
#include <cmath>
#include <data.hpp>
#include <gaussian_elimination.hpp>

template <typename T, std::size_t N>
std::pair<Mat<T, N, N>, Mat<T, N, N> > LU_decomposition(const Mat<T, N, N> &mat){
    Mat<T, N, N> L(0);
    Mat<T, N, N> U(0);
    for(int i = 0;i < N;i++){
        for(int j = 0;j < N;j++){
            if(i >= j){
                U.at(i, j) = mat.at(i, j);
            }else{
                L.at(i, j) = mat.at(i, j);
            }
            if(i == j){
                L.at(i, j) = 1;
            }
        }
    }
    return {L, U};
}
template <typename T, std::size_t N>
Mat<T, 1, N> LU_Gaussian(const Mat<T, N, N> &mat, const Mat<T, 1, N> &vec){
    auto LU = LU_decomposition(mat);
    auto y = gaussian_elimination(LU.first, vec);
    auto x = gaussian_elimination(LU.second, vec);
    return x;
}

#endif //NUMERICAL_ANALYSIS_LU_DECOMPOSITION_HPP
