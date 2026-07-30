#include <string>

using namespace std;

class Solution {
public:
  int minimumPushes(const string &word) {
    const int n = static_cast<int>(word.length());
    const int quo = n / 8, rem = n % 8;
    return 8 * quo * (quo + 1) / 2 + rem * (quo + 1);
  }
};
