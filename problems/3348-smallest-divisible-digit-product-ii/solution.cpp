#include <array>
#include <numeric>
#include <string>

using namespace std;

class Solution {
  using ll = long long;
  using ull = unsigned long long;

  static constexpr int MAX_NUM = static_cast<int>(2 * 1e5);
  static inline string ans = string(MAX_NUM + 1, '0');
  static inline array<ll, MAX_NUM + 1> remaining{};

  static constexpr array<array<int, 10>, 10> GCD = []() {
    array<array<int, 10>, 10> GCD{};
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < i; j++) {
        GCD[i][j] = gcd(i, j);
      }
    }
    return GCD;
  }();

public:
  string smallestNumber(string &num, long long t) {
    // prime factor check
    ll t_copy = t >> countr_zero(static_cast<ull>(t));
    for (int div : {3, 5, 7}) {
      while (t_copy % div == 0)
        t_copy /= div;
    }

    if (t_copy != 1)
      return "-1";

    const int n = static_cast<int>(num.size());
    int pos = n - 1;

    // prefix
    remaining[0] = t, remaining[n] = 0;
    for (int i = 0; i < n; i++) {
      const ll digit = num[i] - '0';
      if (digit == 0) {
        pos = i;
        break;
      }
      remaining[i + 1] = remaining[i] / GCD[digit][remaining[i] % digit];
    }

    if (remaining[n] == 1)
      return num;

    // greedy fill
    for (int i = pos; i >= 0; i--) {
      while (++num[i] <= '9') {
        const ll digit = num[i] - '0';
        ll curr = remaining[i] / GCD[digit][remaining[i] % digit];
        char k = 9;
        for (int j = n - 1; j > i; j--) {
          while (curr % k > 0)
            k--;

          curr /= k;
          num[j] = '0' + k;
        }
        if (curr == 1)
          return num;
      }
    }

    // extension case (len = n + 1)
    int idx = MAX_NUM;
    for (char i = 9; i > 1; i--) {
      while (t % i == 0) {
        ans[idx--] = i + '0';
        t /= i;
      }
    }

    while (MAX_NUM - idx < n + 1)
      ans[idx--] = '1';

    return ans.substr(idx + 1);
  }
};
