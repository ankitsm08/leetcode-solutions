#include <string>

using namespace std;

class Solution {
public:
  bool checkIfPangram(string sentence) {
    if (sentence.length() < 26)
      return false;

    bool seen[26] = {false};

    for (const char ch : sentence) {
      seen[ch - 'a'] = true;
    }

    for (const bool b : seen)
      if (!b)
        return false;
    return true;
  }
};
