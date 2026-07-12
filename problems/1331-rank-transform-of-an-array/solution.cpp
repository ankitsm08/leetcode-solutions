#include <algorithm>
#include <array>
#include <vector>

using namespace std;

class Solution {
  static inline constexpr int MAXN = 100000;
  static inline array<pair<int, int>, MAXN> idxArr;

public:
  vector<int> arrayRankTransform(vector<int> &arr) {
    const int n = static_cast<int>(arr.size());
    if (n == 0)
      return {};

    for (int i = 0; i < n; i++)
      idxArr[i] = {arr[i], i};

    sort(idxArr.begin(), idxArr.begin() + n,
         [](const auto &a, const auto &b) { return a.first < b.first; });

    vector<int> ans(n);
    ans[idxArr[0].second] = 1;
    for (int rank = 1, i = 1; i < n; i++) {
      rank += idxArr[i].first != idxArr[i - 1].first;
      ans[idxArr[i].second] = rank;
    }

    return ans;
  }
};
