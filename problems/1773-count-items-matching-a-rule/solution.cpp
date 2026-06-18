#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue) {
    const int idx = (ruleKey == "color") + 2 * (ruleKey == "name");

    int count = 0;
    for (const auto &item : items) {
      if (item[idx] == ruleValue) {
        count++;
      }
    }

    return count;
  }
};
