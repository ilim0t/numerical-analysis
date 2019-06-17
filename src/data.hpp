#ifndef NUMERICAL_ANALYSIS_LIB2_LIBRARY_H
#define NUMERICAL_ANALYSIS_LIB2_LIBRARY_H

template <typename T>
class vector
{
protected:
  std::vector<T> data;

  vector(const int &, const std::function<T(int)> &);

  vector(const int &, const T & = 0);
};

template <typename T>
class matrix
{
private:
  std::vector<std::vector<T>> data;

  matrix(const std::vector<int> &, const std::function<T(std::vector<int>)> &);

  matrix(const std::vector<int> &, const T & = 0);

public:
  //    friend std::ostream &operator<<(std::ostream &, const matrix<T> &);
};

template <typename T>
std::ostream &operator<<(std::ostream &, const matrix<T> &);

#endif //NUMERICAL_ANALYSIS_LIB2_LIBRARY_H
