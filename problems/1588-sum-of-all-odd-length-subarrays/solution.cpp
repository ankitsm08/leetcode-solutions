#include <vector>

using namespace std;

class Solution {
public:
  int sumOddLengthSubarrays(vector<int> &arr) {
    const size_t n = arr.size();

    int sum = 0;
    for (size_t i = 0; i < n; i++)
      sum += arr[i] * (((i + 1) * (n - i) + 1) / 2);

    return sum;
  }
};
