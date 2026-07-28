#include <array>
#include <string>

using namespace std;

class Solution {
public:
  string smallestPalindrome(string &s) {
    array<int, 26> freq{};
    for (const char c : s)
      freq[c - 'a']++;

    const int n = static_cast<int>(s.length());

    if (n % 2 == 1) {
      for (char i = 0; i < 26; i++) {
        if (freq[i] % 2 == 1) {
          s[n / 2] = 'a' + i;
          freq[i]--;
          break;
        }
      }
    }

    int idx = 0;
    for (char i = 0; i < 26; i++) {
      while (freq[i] > 0) {
        s[idx] = s[n - idx - 1] = 'a' + i;
        idx++;
        freq[i] -= 2;
      }
    }

    return s;
  }
};
