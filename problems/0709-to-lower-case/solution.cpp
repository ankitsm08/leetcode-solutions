#include <string>

using namespace std;

class Solution {
public:
  string toLowerCase(string s) {
    for (size_t i = 0; i < s.length(); i++) {
      char ch = s[i];
      if (ch >= 'A' && ch <= 'Z')
        s[i] = 'a' + (ch - 'A');
    }

    return s;
  }
};
