#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    const int n = static_cast<int>(g.size());
    const int m = static_cast<int>(s.size());

    ranges::sort(g);
    ranges::sort(s);

    int i = 0;
    for (int j = 0; i < n && j < m; j++)
      i += g[i] <= s[j];

    return i;
  }
};
