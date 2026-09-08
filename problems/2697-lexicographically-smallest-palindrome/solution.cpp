#include <string>

using namespace std;

class Solution {
public:
  string makeSmallestPalindrome(string &s) {
    const int n = static_cast<int>(s.length());

    for (int i = 0; i < n / 2; i++) {
      char &ch1 = s[i];
      char &ch2 = s[n - i - 1];

      ch1 = ch2 = min(ch1, ch2);
    }

    return s;
  }
};
