#include <array>
#include <cstdint>
#include <string>

using namespace std;

class Solution {
public:
  int longestPalindrome(const string &s) {
    array<uint16_t, 26 * 2> freq{};

    for (char ch : s) {
      if (ch >= 'a')
        freq[ch - 'a']++;
      else
        freq[26 + ch - 'A']++;
    }

    int len = 0;
    bool has_odd = false;
    for (auto f : freq) {
      const bool is_odd = f % 2;
      len += f - is_odd;
      has_odd |= is_odd;
    }

    return len + has_odd;
  }
};
