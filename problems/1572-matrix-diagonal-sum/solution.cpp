#include <vector>

using namespace std;

class Solution {
public:
  int diagonalSum(vector<vector<int>> &mat) {
    const size_t n = mat.size();
    int sum = 0;
    for (size_t i = 0; i < n; i++) {
      sum += mat[i][i] + mat[i][n - i - 1];
    }
    if (n & 1) {
      sum -= mat[n >> 1][n >> 1];
    }
    return sum;
  }
};
