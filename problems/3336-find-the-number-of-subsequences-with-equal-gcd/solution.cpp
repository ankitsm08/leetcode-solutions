#include <algorithm>
#include <array>
#include <cstring>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MAX = 201;
  static constexpr int mod = static_cast<int>(1e9) + 7;

  static inline const array<array<int, MAX>, MAX> gcds = []() {
    array<array<int, MAX>, MAX> res{};
    for (int i = 0; i < MAX; i++)
      for (int j = 0; j < MAX; j++)
        res[i][j] = gcd(i, j);
    return res;
  }();

  static inline array<array<array<int, MAX>, MAX>, 2> dp;

  static inline void madd(int &a, int b) {
    if ((a += b) >= mod)
      a -= mod;
  }

public:
  int subsequencePairCount(vector<int> &nums) {
    const int m = *max_element(nums.begin(), nums.end());

    int curr = 0;
    memset(dp[curr].data(), 0, sizeof(dp[curr][0]) * (m + 1));
    dp[curr][0][0] = 1;

    for (int num : nums) {
      const int next = curr ^ 1;
      memset(dp[next].data(), 0, sizeof(dp[next][0]) * (m + 1));

      for (int j = 0; j <= m; j++) {
        const int divisor1 = gcds[j][num];

        for (int k = 0; k <= m; k++) {
          const int val = dp[curr][j][k];
          if (val == 0)
            continue;

          const int divisor2 = gcds[k][num];

          madd(dp[next][j][k], val);
          madd(dp[next][divisor1][k], val);
          madd(dp[next][j][divisor2], val);
        }
      }

      curr = next;
    }

    int subsequences = 0;
    for (int i = 1; i <= m; i++)
      madd(subsequences, dp[curr][i][i]);

    return subsequences;
  }
};
