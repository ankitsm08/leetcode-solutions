#include <limits>
#include <unordered_map>
#include <vector>

using namespace std;

#include <memory_resource>

pmr::unsynchronized_pool_resource pool;

class Solution {
public:
  int minMirrorPairDistance(vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    pmr::unordered_map<int, int> map(&pool);
    map.reserve(n);

    int min_dist = numeric_limits<int>::max();
    for (int i = 0; i < n; i++) {
      const auto prev_reverse = map.find(nums[i]);
      if (prev_reverse != map.cend()) {
        const int dist = i - prev_reverse->second;
        if (dist < min_dist && (min_dist = dist) == 1) {
          return 1;
        }
      }

      int reverse = 0, copy = nums[i];
      for (; copy > 0; copy /= 10)
        reverse = reverse * 10 + copy % 10;

      map[reverse] = i;
    }

    return min_dist == numeric_limits<int>::max() ? -1 : min_dist;
  }
};
