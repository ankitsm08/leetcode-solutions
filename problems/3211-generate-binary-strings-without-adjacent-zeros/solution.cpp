#include <array>
#include <string>
#include <vector>

using namespace std;

class Solution {
  static inline const array<int, 21> FIB = []() {
    array<int, 21> f{};
    f[1] = 1; // F1
    f[2] = 1; // F2
    for (int i = 3; i <= 20; ++i)
      f[i] = f[i - 1] + f[i - 2];
    return f;
  }();

public:
  void solve(int idx, string &current, vector<string> &answer, int n) {
    if (idx == n) {
      answer.push_back(current);
      return;
    }

    current.push_back('1');
    solve(idx + 1, current, answer, n);
    current.pop_back();

    if (current.empty() || current.back() != '0') {
      current.push_back('0');
      solve(idx + 1, current, answer, n);
      current.pop_back();
    }
  }

  vector<string> validStrings(int n) {
    if (n == 1)
      return {"0", "1"};

    vector<string> answer;
    answer.reserve(FIB[n + 2]);

    string current;
    current.reserve(n);

    solve(0, current, answer, n);
    return answer;
  }
};
