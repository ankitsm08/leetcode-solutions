#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2) {
    constexpr int MIN_RANGE = 1;
    constexpr int MAX_RANGE = 100;
    constexpr size_t SIZE = MAX_RANGE - MIN_RANGE + 1;

    bool seen1[SIZE] = {false};
    bool seen2[SIZE] = {false};

    int count1 = 0, count2 = 0;
    for (int num : nums1) {
      seen1[num - MIN_RANGE] = true;
    }
    for (int num : nums2) {
      count2 += seen1[num - MIN_RANGE];
      seen2[num - MIN_RANGE] = true;
    }
    for (int num : nums1) {
      count1 += seen2[num - MIN_RANGE];
    }

    return {count1, count2};
  }
};
