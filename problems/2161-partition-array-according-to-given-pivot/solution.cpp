#include <vector>

using namespace std;

class Solution {
public:
  vector<int> pivotArray(vector<int> &nums, int pivot) {
    const size_t n = nums.size();
    vector<int> ans(n, pivot);

    size_t front = 0, back = n - 1;
    for (size_t i = 0, j = n; i < n && j-- > 0; i++) {
      if (nums[i] < pivot)
        ans[front++] = nums[i];
      if (nums[j] > pivot)
        ans[back--] = nums[j];
    }

    return ans;
  }
};
