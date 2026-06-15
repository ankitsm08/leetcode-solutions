#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string restoreString(string s, vector<int> &indices) {
    string shuffled(s.length(), '\0');

    for (int i = 0; i < indices.size(); i++) {
      shuffled[indices[i]] = s[i];
    }

    return shuffled;
  }
};
