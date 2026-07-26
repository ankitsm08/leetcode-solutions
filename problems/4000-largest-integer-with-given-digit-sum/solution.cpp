#include <algorithm>

class Solution {
public:
  int largestInteger(int n, int s) {
    if (s == 0)
      return 0;
    if (s > 9 * n)
      return -1;

    int num = 0;
    while (n--) {
      const int digit = std::min(s, 9);
      num = num * 10 + digit;
      s -= digit;
    }

    return num;
  }
};
