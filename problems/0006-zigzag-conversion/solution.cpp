#include <string>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {
    const size_t R = static_cast<size_t>(numRows);
    const size_t n = s.length();

    // edge cases
    if (n <= 2 || R >= n || R <= 1)
      return s;

    string ans;
    ans.reserve(n);

    // first row
    size_t idx = 0;
    while (idx < n) {
      ans.push_back(s[idx]);
      idx += 2 * (R - 1);
    }

    // middle alternating
    for (size_t i = 1; i < R - 1; i++) {
      bool down = true;
      const size_t step_down = 2 * (R - i - 1);
      const size_t step_up = 2 * i;
      idx = i;
      while (idx < n) {
        ans.push_back(s[idx]);
        idx += down ? step_down : step_up;
        down = !down;
      }
    }

    // last row
    idx = R - 1;
    while (idx < n) {
      ans.push_back(s[idx]);
      idx += 2 * (R - 1);
    }

    return ans;
  }
};
