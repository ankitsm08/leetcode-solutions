#include <algorithm>
#include <array>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MAX_N = static_cast<int>(1e5);
  static inline array<int, MAX_N> depths{};

public:
  long long weightedSum(vector<int> &parent, vector<int> &nums) {
    const int n = static_cast<int>(parent.size());

    fill(depths.begin(), depths.begin() + n, -1);

    auto setDepth = [&](this auto &&setDepth, int node) -> int {
      if (depths[node] == -1)
        return depths[node] = setDepth(parent[node]) + 1;
      return depths[node];
    };

    parent[0] = 0;
    depths[0] = 1;
    for (int i = 1; i < n; i++)
      setDepth(i);

    const int height = *max_element(depths.begin(), depths.begin() + n);

    long long sum = 0;
    for (int i = 0; i < n; i++)
      sum += static_cast<long long>(nums[i]) * (height - depths[i] + 1);

    return sum;
  }
};
