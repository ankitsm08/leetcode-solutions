#include <array>

using namespace std;

class Solution {
  using ll = long long;
  static constexpr int MOD = static_cast<int>(1e9 + 7);
  static constexpr int MAX_K = static_cast<int>(5 * 1e5);

  static inline array<int, MAX_K + 1> fact, inv_fact;

  static int modPow(int x, int pow) {
    ll ans = 1, exp = x;

    while (pow) {
      if (pow & 1)
        ans = (ans * exp) % MOD;
      exp = (exp * exp) % MOD;
      pow >>= 1;
    }

    return static_cast<int>(ans);
  }

  static inline bool init = []() {
    fact[0] = 1;
    for (int i = 1; i <= MAX_K; i++)
      fact[i] = 1LL * fact[i - 1] * i % MOD;

    inv_fact[MAX_K] = modPow(fact[MAX_K], MOD - 2);
    for (int i = MAX_K; i >= 1; i--)
      inv_fact[i - 1] = 1LL * inv_fact[i] * i % MOD;

    return true;
  }();

public:
  inline int nCr(int n, int r) {
    return (1LL * fact[n] * inv_fact[r] % MOD) * inv_fact[n - r] % MOD;
  }

  int countValidSequences(int n, int k) {
    const int total = nCr(n - 1, k - 1);

    if ((n - k) % 2 != 0)
      return total;

    const int odd = nCr((n - k) / 2 + k - 1, k - 1);

    return (0LL + total - odd + MOD) % MOD;
  }
};
