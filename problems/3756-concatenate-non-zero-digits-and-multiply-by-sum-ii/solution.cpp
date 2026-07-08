#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MOD = static_cast<int>(1e9) + 7;
  static constexpr int MAX = 100'001;
  inline static array<int, MAX> pow10;

  inline static const int init = []() {
    pow10[0] = 1;
    for (size_t i = 1; i < MAX; i++)
      pow10[i] = pow10[i - 1] * 10LL % MOD;
    return 0;
  }();

public:
  vector<int> sumAndMultiply(const string &s, vector<vector<int>> &queries) {
    vector<int> ans;
    ans.reserve(queries.size());

    const size_t n = s.size();
    vector<int> sumPrefix(n + 1, 0);
    vector<int> digitPrefix(n + 1, 0);
    vector<int> numLen(n + 1, 0);

    for (size_t i = 0; i < n; i++) {
      const int digit = s[i] - '0';
      sumPrefix[i + 1] = sumPrefix[i] + digit;

      if (digit > 0) {
        digitPrefix[i + 1] = (digitPrefix[i] * 10LL + digit) % MOD;
        numLen[i + 1] = numLen[i] + 1;
      } else {
        digitPrefix[i + 1] = digitPrefix[i];
        numLen[i + 1] = numLen[i];
      }
    }

    for (auto &query : queries) {
      size_t l = query[0], r = query[1] + 1;

      const size_t subLen = numLen[r] - numLen[l];
      const long long excess = digitPrefix[l] * 1LL * pow10[subLen] % MOD;
      const long long subNum = (digitPrefix[r] - excess + MOD) % MOD;

      ans.push_back(subNum * (sumPrefix[r] - sumPrefix[l]) % MOD);
    }

    return ans;
  }
};
