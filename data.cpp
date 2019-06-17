#include <cassert>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <tuple>

class vector
{
protected:
  std::vector<double> data;

  vector(int size, std::function<double(int)> func)
  {
    for (int i = 0; i < size; ++i)
    {
      data[i] = func(i);
    }
  }

  vector(int size, double init_value = 0)
  {
    data = std::vector<double>(size, init_value);
  }

  // 作るメンバ関数
  // operator stream
  //   dot (行列同士, ベクトル の２つ)
  // copy
};

class matrix
{
protected:
  std::vector<std::vector<std::complex(std::complex<double>)>> data;

  matrix(std::vector<int> shape, std::function<std::complex(std::complex<double>)(std::vector<int>)> func)
  {
    // int dim = shape.size();
    // assert(dim == 2);

    for (int i = 0; i < shape.at(0); ++i)
    {
      for (int j = 0; j < shape.at(1); ++j)
      {
        data[i][j] = func(std::vector<int>({i, j}));
      }
    }
  }

  matrix(std::vector<int> shape,
         std::complex(std::complex<double>) init_value = 0)
  {
    int dim = shape.size();
    assert(dim == 2);
    data = std::vector<std::vector<std::complex(std::complex<double>)>>(
        shape.at(0), std::vector<std::complex(std::complex<double>)>(
                         shape.at(1), init_value));
  }

public:
  matrix forward_erase();
  double norm(int p = 2)
  {
    assert(p == 1 || p == 2 || std::isinf(p));

    if (p == 1)
    {
      int raw_size = data.size();
      int col_size = data.at(0).size();
      std::vector<double> col_sum(col_size, 0);
      for (auto col : data)
      {
        for (int j = 0; j < col_size; ++j)
        {
          col_sum[j] += std::norm(col.at(j))
        }
        return *std::max_element(col_sum.begin(), col_sum.end());
      }
    }
    else if (p == 2)
    {
    }
    else
    {
    }

    double norm()

    // 作るメンバ関数
    // operator stream
    //   dot (行列同士, ベクトル の２つ)
    // copy
    //
    // constructer(functionを引数に)
    //
  };
