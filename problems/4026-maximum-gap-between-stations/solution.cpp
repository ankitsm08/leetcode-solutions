#include <array>
#include <string>

using namespace std;

class Solution {
  static constexpr int MAX_N = static_cast<int>(1e5);
  static inline array<int, MAX_N> last;

public:
  int maximumGap(const string &skill, const string &station) {
    const int n = static_cast<int>(skill.size());
    const int m = static_cast<int>(station.size());

    if (n == 1)
      return 0;

    for (int i = n - 1, l = m - 1; i >= 0; i--) {
      while (l > 0 && skill[i] != station[l])
        l--;
      last[i] = l--;
    }

    int maxGap = 0;
    for (int i = 1, first = 0; i < n; i++) {
      while (first < m - 1 && skill[i - 1] != station[first])
        first++;
      maxGap = max(maxGap, last[i] - first++);
    }
    return maxGap;
  }
};
