#include <array>
#include <string>

using namespace std;

class Solution {
public:
  int numberOfSubstrings(string s) {
    const size_t n = s.length();
    array<int, 3> ch{};

    int substrings = 0;
    size_t left = 0, right = 0;
    while (right < n) {
      ch[s[right++] - 'a']++;

      while (ch[0] > 0 && ch[1] > 0 && ch[2] > 0)
        ch[s[left++] - 'a']--;

      substrings += left;
    }

    return substrings;
  }
};
