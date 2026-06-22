#include <algorithm>
#include <array>
#include <string>

using namespace std;

class Solution {
public:
  int maxNumberOfBalloons(const string &text) {
    array<int, 26> freq = {0};
    for (const char ch : text)
      freq[ch - 'a']++;

    return min({freq['b' - 'a'], freq['a' - 'a'], freq['l' - 'a'] / 2, freq['o' - 'a'] / 2,
                freq['n' - 'a']});
  }
};
