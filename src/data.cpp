#include <cassert>
#include <cmath>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <vector>

template <typename T>
class vector
{
protected:
  std::vector<T> data;

  // 関数を用いた初期化
  vector(const int &size, const std::function<T(int)> &func)
  {
    assert(size > 0);
    for (int i = 0; i < size; ++i)
    {
      data[i] = func(i);
    }
  }

  vector(const int &size, const T &init_value = 0)
  {
    assert(size > 0);
    data = std::vector<T>(size, init_value);
  }

  // 作るメンバ関数
  // operator stream
  //   dot (行列同士, ベクトル の２つ)
  // copy
};

template <typename T>
class matrix
{
private:
  std::vector<std::vector<T>> data;

  matrix(const std::vector<int> &shape, const std::function<T(std::vector<int>)> &func)
  {
    assert(shape.size() == 2);
    assert(shape.at(0) > 0 && shape.at(1) > 0);

    for (int i = 0; i < shape.at(0); ++i)
    {
      for (int j = 0; j < shape.at(1); ++j)
      {
        data[i][j] = func(std::vector<int>({i, j}));
      }
    }
  }

  matrix(const std::vector<int> &shape, const T &init_value = 0)
  {
    assert(shape.size() == 2);
    assert(shape.at(0) > 0 && shape.at(1) > 0);

    data = std::vector<std::vector<T>>(shape.at(0), std::vector<T>(shape.at(1), init_value));
  }

public:
  //    friend std::ostream &operator<<(std::ostream &, const matrix<T> &);

  // std::tuple<matrix<T>, vector<T>> forward_erase(vector<T> vec);
  // double norm(int p = 2);
};

template <typename T>
std::ostream &operator<<(std::ostream &stream, const matrix<T> &mat)
{
  for (auto raw : mat.data)
  {
    for (auto x : raw)
    {
      stream << x;
    }
    stream << std::endl;
  }
  return stream;
};
