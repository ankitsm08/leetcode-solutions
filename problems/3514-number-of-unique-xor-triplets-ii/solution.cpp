#include <algorithm>
#include <array>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MAX_VAL = 1500;
  static constexpr int MAX_XOR = (1 << (31 - __builtin_clz(MAX_VAL) + 1)) - 1;
  static inline array<bool, MAX_VAL + 1> unique_nums{};
  static inline array<bool, MAX_XOR + 1> unique_pair_xors{};
  static inline array<bool, MAX_XOR + 1> unique_triplet_xors{};

public:
  int uniqueXorTriplets(vector<int> &nums) {
    const int mx = *max_element(nums.begin(), nums.end());

    fill(unique_nums.begin(), unique_nums.begin() + mx + 1, false);
    for (int num : nums)
      unique_nums[num] = true;

    int max_xor = (1 << (31 - __builtin_clz(mx) + 1)) - 1;
    fill(unique_pair_xors.begin(), unique_pair_xors.begin() + max_xor + 1, false);

    unique_pair_xors[0] = true; // x ^ x = 0
    for (int i = 0; i <= mx - 1; i++) {
      if (!unique_nums[i])
        continue;
      for (int j = i; j <= mx; j++) {
        if (unique_nums[j])
          unique_pair_xors[i ^ j] = true;
      }
    }

    fill(unique_triplet_xors.begin(), unique_triplet_xors.begin() + max_xor + 1, false);
    for (int i = 0; i <= mx; i++) {
      if (!unique_nums[i])
        continue;
      for (int j = 0; j <= max_xor; j++) {
        if (unique_pair_xors[j])
          unique_triplet_xors[i ^ j] = true;
      }
    }

    return accumulate(unique_triplet_xors.begin(), unique_triplet_xors.begin() + max_xor + 1, 0);
  }
};
