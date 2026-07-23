#include <vector>

using namespace std;

class Solution {
public:
  int uniqueXorTriplets(vector<int> &nums) {
    const int n = static_cast<int>(nums.size());
    return n <= 2 ? n : 1 << (31 - __builtin_clz(n) + 1);
  }
};
