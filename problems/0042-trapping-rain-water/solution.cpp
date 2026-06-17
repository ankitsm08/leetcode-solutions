#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &height) {
    if (height.empty())
      return 0;

    int leftMax = 0, rightMax = 0;
    size_t left = 0, right = height.size() - 1;

    int water = 0;
    while (left <= right) {
      if (leftMax <= rightMax) {
        leftMax = max(leftMax, height[left]);
        water += leftMax - height[left];
        left++;
      } else {
        rightMax = max(rightMax, height[right]);
        water += rightMax - height[right];
        right--;
      }
    }

    return water;
  }
};
