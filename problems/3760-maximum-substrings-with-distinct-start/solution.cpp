#include <array>
#include <string>

using namespace std;

class Solution {
public:
  int maxDistinct(const string &s) {
    int unique = 0;
    array<bool, 26> present{false};

    for (char c : s) {
      if (!present[c - 'a']) {
        present[c - 'a'] = true;
        if (++unique == 26)
          return 26;
      }
    }

    return unique;
  }
};
