#include <array>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    array<int, 256> freq = {0};
    int l = 0, r = 0, ans = 0;

    while (r < s.length()) {
      freq[s[r]]++;

      while (freq[s[r]] > 1) {
        freq[s[l]]--;
        l++;
      }

      ans = max(ans, r - l + 1);
      r++;
    }

    return ans;
  }
};
