#include <bitset>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MAX_NUM = 100;

public:
  int missingMultiple(vector<int> &nums, int k) {
    bitset<MAX_NUM + 1> seen;
    for (int num : nums)
      seen.set(num);

    int num = 0;
    while ((num += k) <= MAX_NUM && seen.test(num))
      ;

    return num;
  }
};
