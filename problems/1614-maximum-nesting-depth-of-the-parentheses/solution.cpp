#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  int maxDepth(string s) {
    int maxDepth = 0;
    int depth = 0;

    for (char ch : s) {
      if (ch == '(') {
        depth++;
        maxDepth = max(maxDepth, depth);
      } else if (ch == ')') {
        depth--;
      }
    }

    return maxDepth;
  }
};
