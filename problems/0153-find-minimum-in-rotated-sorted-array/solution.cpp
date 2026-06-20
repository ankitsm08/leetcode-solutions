#include <vector>

using namespace std;

class Solution {
public:
  int findMin(vector<int> &nums) {
    size_t low = 0, high = nums.size() - 1;

    while (low < high) {
      size_t mid = low + ((high - low) >> 1);

      if (nums[mid] > nums[high]) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }

    return nums[low];
  }
};
