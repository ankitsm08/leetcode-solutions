#include <algorithm>
#include <memory_resource>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  static inline pmr::unsynchronized_pool_resource pool;

public:
  int maxSubarrayLength(vector<int> &nums, int k) {
    const int n = static_cast<int>(nums.size());
    pmr::unordered_map<int, int> freq(&pool);

    int maxSize = 0;

    for (int i = 0, j = 0; j < n; j++) {
      freq[nums[j]]++;

      while (freq[nums[j]] > k)
        freq[nums[i++]]--;

      maxSize = max(maxSize, j - i + 1);
    }

    return maxSize;
  }
};
