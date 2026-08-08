#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MAX_N = static_cast<int>(3e5);
  static inline array<int, MAX_N> last{};
  static inline array<int, MAX_N> ans{};

public:
  vector<int> validSequence(const string &word1, const string &word2) {
    const int n = static_cast<int>(word1.size());
    const int m = static_cast<int>(word2.size());

    fill(last.begin(), last.begin() + m, -1);

    last[m] = n;
    for (int i = m - 1, j = n - 1; i >= 0; i--) {
      while (j >= 0 && word2[i] != word1[j])
        j--;

      if (j < 0)
        break;

      last[i] = j--;
    }

    int i = 0;
    bool changed = false;
    for (int j = 0; i < m && j < n; j++) {
      const bool same = word2[i] == word1[j];

      if (same || (!changed && last[i + 1] > j)) {
        ans[i++] = j;
        changed = changed || !same;
      }
    }

    return vector<int>{ans.begin(), ans.begin() + (i == m ? m : 0)};
  }
};
