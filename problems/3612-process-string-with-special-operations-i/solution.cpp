#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  string processStr(string s) {
    string ans;

    for (const char ch : s) {
      if (ch == '*') {
        if (!ans.empty())
          ans.pop_back();
      } else if (ch == '#') {
        ans.append(ans);
      } else if (ch == '%') {
        reverse(ans.begin(), ans.end());
      } else {
        ans.push_back(ch);
      }
    }

    return ans;
  }
};
