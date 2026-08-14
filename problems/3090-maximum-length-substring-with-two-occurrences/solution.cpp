#include <algorithm>
#include <array>
#include <string>

using namespace std;

class Solution {
  static inline array<int8_t, 26> freq;

public:
  int maximumLengthSubstring(const string &s) {
    const int n = static_cast<int>(s.length());
    freq.fill(0);

    int maxSize = 0;
    for (int i = 0, j = 0; j < n; j++) {
      freq[s[j] - 'a']++;

      while (freq[s[j] - 'a'] > 2)
        freq[s[i++] - 'a']--;

      maxSize = max(maxSize, j - i + 1);
    }

    return maxSize;
  }
};
