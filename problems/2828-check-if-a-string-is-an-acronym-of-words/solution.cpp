#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isAcronym(const vector<string> &words, const string &s) {
    if (words.size() != s.size())
      return false;

    int idx = 0;
    for (const string &word : words) {
      if (word[0] != s[idx++])
        return false;
    }

    return true;
  }
};
