#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  bool canThreePartsEqualSum(vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0);
    if (sum % 3 != 0)
      return false;

    sum /= 3;
    partial_sum(arr.begin(), arr.end(), arr.begin());

    auto it1 = ranges::find(arr.begin(), arr.end() - 1, sum);
    if (it1 == arr.end() - 1)
      return false;

    auto it2 = ranges::find(it1 + 1, arr.end() - 1, sum * 2);
    return it2 != arr.end() - 1;
  }
};
