#include <algorithm>
#include <cstddef>
#include <string>

using namespace std;

class Solution {
public:
  string reverseWords(string s) {
    const size_t n = s.length();

    size_t l = 0;
    for (size_t i = 0; i < n; i++) {
      if (s[i] == ' ') {
        reverse(s.begin() + l, s.begin() + i);
        l = i + 1;
      }
    }
    reverse(s.begin() + l, s.end());

    return s;
  }
};
