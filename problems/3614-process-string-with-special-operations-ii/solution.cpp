#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  char processStr(string s, long long k) {
    using ull = unsigned long long;
    ull len = 0;

    for (char ch : s) {
      if (ch == '*') {
        if (len > 0)
          len--;
      } else if (ch == '#') {
        len *= 2;
      } else if (ch != '%') {
        len++;
      }
    }

    ull K = static_cast<ull>(k);
    if (K >= len)
      return '.';

    for (size_t i = s.size(); i-- > 0;) {
      const char ch = s[i];

      if (ch == '*') {
        len++;
      } else if (ch == '#') {
        if (K >= (len /= 2))
          K = K - len;
      } else if (ch == '%') {
        K = len - K - 1;
      } else {
        if (K == len-- - 1)
          return ch;
      }
    }

    return '.';
  }
};

int main() {
  Solution sol;
  cout << sol.processStr("a#b%*", 1) << endl;
  cout << sol.processStr("cd%#*#", 3) << endl;
  cout << sol.processStr("z*%", 0) << endl;
  assert(sol.processStr("a#b%*", 1) == 'a');
  assert(sol.processStr("cd%#*#", 3) == 'd');
  assert(sol.processStr("z*%", 0) == '.');
  return 0;
}
