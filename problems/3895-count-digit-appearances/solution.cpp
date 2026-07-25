#include <vector>

using namespace std;

class Solution {
public:
  int countDigitOccurrences(vector<int> &nums, int digit) {
    int count = 0;
    for (int num : nums)
      for (; num > 0; num /= 10)
        count += num % 10 == digit;
    return count;
  }
};
