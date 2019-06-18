#include <array>
#include <functional>
#include <iostream>
#include <initializer_list>

template <typename T, std::size_t N, std::size_t M>
struct Mat : std::array<std::array<T, M>, N>
{
  typedef std::array<std::array<T, M>, N> super;

public:
  Mat(std::initializer_list<std::array<T, M>> list)
  {
    auto begin = list.begin();
    if (N != list.size())
    {
      std::cout << "ERROR";
    }
    for (int i = 0; i < list.size(); ++i)
    {
      super::at(i) = begin[i];
    }
  }

  Mat(const T &init_value)
  {
    for (int i=0; i< super::size(); ++i)
    {
      super::at(i).fill(init_value);
    }
  }

  Mat(const std::function<T(int, int)> &func)
  {
    for (int i = 0; i < N; ++i)
    {
      for (int j = 0; j < M; ++j)
      {
        super::at(i).at(j) = func(i, j);
      }
    }
  };
};
