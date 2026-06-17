#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int maxWater = 0;
    size_t left = 0, right = height.size() - 1;

    while (left < right) {
      const int currentWater = (int)(right - left) * min(height[left], height[right]);
      maxWater = max(maxWater, currentWater);

      if (height[left] < height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return maxWater;
  }
};
