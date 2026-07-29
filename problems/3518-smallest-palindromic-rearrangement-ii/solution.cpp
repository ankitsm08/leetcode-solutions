#include <array>
#include <cstdint>
#include <string>

using namespace std;

class Solution {
  static constexpr int MAX_K = static_cast<int>(1e6);

  static int nCr(int n, int r) {
    static constexpr auto N = 36;
    static constexpr auto Comb = []() {
      array<array<int, N>, N> comb{};

      for (int i = 0; i < N; i++) {
        comb[i][0] = comb[i][i] = 1;
        for (int j = 1; j <= i / 2; j++) {
          int64_t val = comb[i - 1][j - 1] + comb[i - 1][j];
          if (val > MAX_K)
            val = MAX_K + 1;
          comb[i][j] = comb[i][i - j] = static_cast<int>(val);
        }
      }

      return comb;
    }();

    if (n < N)
      return Comb[n][r];
    if (n - r < r)
      r = n - r;

    int64_t ans = 1;
    for (int i = 1; i <= r; i++) {
      ans = ans * (n - i + 1) / i;
      if (ans > MAX_K)
        return MAX_K + 1;
    }
    return static_cast<int>(ans);
  }

  static int nP_freq(int n, const array<int, 26> &freq) {
    int64_t ans = 1;
    for (int f : freq) {
      if (f == 0)
        continue;
      ans *= nCr(n, f);
      if (ans > MAX_K)
        return MAX_K + 1;
      n -= f;
    }
    return static_cast<int>(ans);
  }

public:
  string smallestPalindrome(string &s, int k) {
    const int n = static_cast<int>(s.length());
    const int n2 = n / 2;

    array<int, 26> freq{};
    for (int i = 0; i < n2; i++)
      freq[s[i] - 'a']++;

    if (k > nP_freq(n2, freq))
      return "";

    int idx = 0;
    int sz = n2;
    for (int i = 0; i < n2; i++) {
      for (char j = 0; j < 26; j++) {
        if (freq[j] == 0)
          continue;

        freq[j]--;
        int perms = nP_freq(--sz, freq);
        if (perms >= k) {
          s[idx++] = 'a' + j;
          break;
        }

        k -= perms;
        freq[j]++;
        sz++;
      }
    }

    for (int i = 0; i < n2; i++)
      s[n - i - 1] = s[i];

    return s;
  }
};
