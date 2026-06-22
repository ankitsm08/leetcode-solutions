#include <array>
#include <climits>
#include <string>

using namespace std;

class Solution {
public:
  int rearrangeCharacters(const string &s, const string &target) {
    array<int, 26> freqS{};
    array<int, 26> freqTarget{};
    for (const char ch : s)
      freqS[ch - 'a']++;
    for (const char ch : target)
      freqTarget[ch - 'a']++;

    int minWords = INT_MAX;
    for (size_t i = 0; i < 26; i++) {
      if (freqTarget[i] != 0) {
        minWords = min(minWords, freqS[i] / freqTarget[i]);
      }
    }

    return minWords;
  }
};
