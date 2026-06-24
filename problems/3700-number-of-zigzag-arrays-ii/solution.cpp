#include <algorithm>
#include <array>
#include <cstdint>
#include <vector>

using namespace std;

class Solution {
public:
  static constexpr int64_t mod = static_cast<int64_t>(1e9) + 7;
  static constexpr size_t MAX_K = 75;

  struct Matrix {
    size_t n;
    array<int64_t, MAX_K * MAX_K> mat;

    Matrix(size_t size) : n(size) { mat.fill(0); }
    Matrix(size_t size, int64_t num) : n(size) { mat.fill(num); }

    inline int64_t &operator()(size_t row, size_t col) { return mat[row * n + col]; }
    inline const int64_t &operator()(size_t row, size_t col) const { return mat[row * n + col]; }

    Matrix operator*(const Matrix &other) const {
      Matrix res(n);

      for (size_t i = 0; i < n; i++) {
        array<__int128, MAX_K> tmp = {0};

        for (size_t k = 0; k < n; k++) {
          const int64_t val1 = (*this)(i, k);
          if (val1 == 0)
            continue;
          for (size_t j = 0; j < n; j++) {
            tmp[j] += static_cast<__int128>(val1) * other(k, j);
          }
        }

        for (size_t j = 0; j < n; j++) {
          res(i, j) = static_cast<int64_t>(tmp[j] % mod);
        }
      }

      return res;
    }
  };

  void mult(const vector<int64_t> &vec, const Matrix &mat, vector<int64_t> &res, size_t K) {
    fill(res.begin(), res.end(), 0);
    for (size_t i = 0; i < K; i++) {
      __int128_t sum = 0;

      for (size_t j = 0; j < K; j++) {
        sum += static_cast<__int128_t>(mat(i, j)) * vec[j];
      }

      res[i] = static_cast<int64_t>(sum % mod);
    }
  }

  int zigZagArrays(int n, int l, int r) {
    if (n == 1)
      return r - l + 1;

    const size_t K = r - l + 1;

    // transition matrix
    Matrix mat(K, 0);

    for (size_t v = 0; v < K; v++) {
      for (size_t u = 0; u < v; u++)
        mat(v, K - 1 - u) = 1;
    }

    // matrix exponentiation
    int exp = n - 1;
    vector<int64_t> res(K, 1);
    vector<int64_t> tmp(res);

    int flips = 0;
    while (exp > 0) {
      if (exp & 1) {
        if (flips++ & 1)
          mult(tmp, mat, res, K);
        else
          mult(res, mat, tmp, K);
      }
      mat = mat * mat;
      exp >>= 1;
    }
    const auto &final_vec = (flips & 1) ? tmp : res;

    int64_t totalValid = 0;
    for (size_t i = 0; i < K; i++) {
      totalValid += final_vec[i];
      if (totalValid >= mod)
        totalValid -= mod;
    }

    totalValid *= 2;
    if (totalValid >= mod)
      totalValid -= mod;

    return static_cast<int>(totalValid);
  }
};
