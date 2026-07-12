#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    const int m = static_cast<int>(matrix.size());
    const int n = static_cast<int>(matrix[0].size());
    int low = 0;
    int high = m * n - 1;

    while (low <= high) {
      const int mid = low + ((high - low) >> 1);
      const int val = matrix[mid / n][mid % n];
      if (val < target) {
        low = mid + 1;
      } else if (val > target) {
        high = mid - 1;
      } else {
        return true;
      }
    }

    return false;
  }
};
