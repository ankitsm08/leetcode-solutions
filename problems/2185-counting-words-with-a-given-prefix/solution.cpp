#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int prefixCount(vector<string> &words, string pref) {
    int count = 0;

    for (const string &word : words) {
      if (word.length() < pref.length())
        continue;

      bool flag = true;
      for (size_t i = 0; i < pref.length(); i++) {
        if (word[i] != pref[i]) {
          flag = false;
          break;
        }
      }

      count += flag;
    }

    return count;
  }
};
