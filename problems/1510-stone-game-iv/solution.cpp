#include <bitset>

using namespace std;

class Solution {
  static constexpr int MAX_N = static_cast<int>(1e5);
  static inline bitset<MAX_N + 1> dp;

  static inline bool init = []() {
    for (int i = 0; i <= MAX_N; i++) {
      if (dp.test(i))
        continue;
      for (int j = 1; j * j <= MAX_N - i; j++)
        dp.set(i + j * j);
    }
    return true;
  }();

public:
  bool winnerSquareGame(int n) { return dp.test(n); }
};
