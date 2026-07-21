#include <string>

using namespace std;

class Solution {
public:
  int maxActiveSectionsAfterTrade(const string &s) {
    int max_delta = 0, delta_l = 0, delta_r = 0;
    int ones = 0;
    char prev = '\0';

    for (const char c : s) {
      if (prev != c && delta_r > 0) {
        max_delta = max(-(delta_l > 0) & (delta_l + delta_r), max_delta);
        delta_l = delta_r;
        delta_r = 0;
      }
      ones += c == '1';
      delta_r += c == '0';
      prev = c;
    }
    if (delta_r > 0 && delta_l > 0)
      max_delta = max(delta_l + delta_r, max_delta);

    return ones + max_delta;
  }
};
