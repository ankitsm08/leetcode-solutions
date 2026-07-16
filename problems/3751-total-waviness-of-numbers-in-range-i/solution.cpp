#include <array>

using namespace std;

class Solution {
  static constexpr int MAX = 100001;

  static inline array<int, MAX> pref{};
  static inline const bool init = []() {
    array<int, MAX> dp{};
    for (int i = 101; i < MAX; i++) {
      const int r = i % 10;
      const int m = (i / 10) % 10;
      const int l = (i / 100) % 10;

      const bool isWavy = (l > m && m < r) || (l < m && m > r);
      dp[i] = dp[i / 10] + isWavy;
      pref[i] = dp[i] + pref[i - 1];
    }
    return true;
  }();

public:
  inline int totalWaviness(int num1, int num2) { return pref[num2] - pref[num1 - 1]; }
};
