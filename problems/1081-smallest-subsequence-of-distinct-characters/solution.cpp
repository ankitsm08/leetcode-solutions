#include <array>
#include <bitset>
#include <string>

using namespace std;

class Solution {
public:
  string smallestSubsequence(const string &s) {
    const int n = static_cast<int>(s.length());

    array<int, 26> last_occur{};
    bitset<26> seen{};

    for (int i = 0; i < n; i++)
      last_occur[s[i] - 'a'] = i;

    string res = "";

    for (int i = 0; i < n; i++) {
      const char ch = s[i];

      if (seen.test(ch - 'a'))
        continue;

      while (!res.empty()) {
        const char top = res.back();
        if (!(ch < top && last_occur[top - 'a'] > i))
          break;
        seen.reset(top - 'a');
        res.pop_back();
      }

      res.push_back(ch);
      seen.set(ch - 'a');
    }

    return res;
  }
};
