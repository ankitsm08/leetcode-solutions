#include <string>

using namespace std;

class Solution {
public:
  int countAsterisks(const string &s) {
    int count = 0;
    bool outside = true;
    for (char c : s) {
      outside = (c == '|') ^ outside;
      count += outside && (c == '*');
    }
    return count;
  }
};
