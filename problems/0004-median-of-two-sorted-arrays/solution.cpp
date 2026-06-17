#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() > nums2.size())
      return findMedianSortedArrays(nums2, nums1);

    const size_t m = nums1.size(), n = nums2.size();
    size_t low = 0, high = m;

    while (low <= high) {
      const size_t i = low + (high - low) / 2;
      const size_t j = (m + n + 1) / 2 - i;

      const int num1_left = i == 0 ? INT_MIN : nums1[i - 1];
      const int num2_left = j == 0 ? INT_MIN : nums2[j - 1];
      const int num1_right = i == m ? INT_MAX : nums1[i];
      const int num2_right = j == n ? INT_MAX : nums2[j];

      if (num1_left > num2_right) {
        high = i - 1;
      } else if (num2_left > num1_right) {
        low = i + 1;
      } else {
        if ((m + n) & 1) {
          return max(num1_left, num2_left);
        } else {
          const int mid1 = max(num1_left, num2_left);
          const int mid2 = min(num1_right, num2_right);
          return static_cast<double>(mid1 + mid2) / 2.0;
        }
      }
    }

    return 0.0;
  }
};

int main() {
  Solution sol = Solution();
  {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
  }
  {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
  }
  {
    vector<int> nums1 = {1};
    vector<int> nums2 = {3, 4};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
  }
  {
    vector<int> nums1 = {2};
    vector<int> nums2 = {};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
  }
}
