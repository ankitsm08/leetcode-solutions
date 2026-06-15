#include <vector>

using namespace std;

class Solution {
public:
  int evenNumberBitwiseORs(vector<int> &nums) {
    int bit_or = 0;
    for (int num : nums) {
      if (!(num & 1)) {
        bit_or |= num;
      }
    }
    return bit_or;
  }
};
