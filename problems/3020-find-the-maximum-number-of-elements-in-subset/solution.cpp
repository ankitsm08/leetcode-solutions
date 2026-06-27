#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

class Solution {
  static constexpr int ONE_E9_SQRT = 31622;

public:
  int maximumLength(vector<int> &nums) {
    bitset<ONE_E9_SQRT + 1> freq1, freq2, sqrset;

    int ones = 0, maxNum = 0, minNum = ONE_E9_SQRT;
    for (const int num : nums) {
      if (num == 1)
        ones++;
      else if (num <= ONE_E9_SQRT) {
        if (!freq1[num]) {
          freq1[num] = true;
        } else {
          freq2[num] = true;
          minNum = min(minNum, num);
          maxNum = max(maxNum, num);
        }
      } else {
        int root = static_cast<int>(sqrt(num));
        if (root * root == num)
          sqrset[root] = true;
      }
    }

    auto get_count = [&](const int num) -> int {
      if (num <= ONE_E9_SQRT)
        return freq1[num] + freq2[num];
      int root = static_cast<int>(sqrt(num));
      return static_cast<int>(root * root == num && root <= ONE_E9_SQRT && sqrset[root]);
    };

    int maxLen = max(1, ones - !(ones & 1));

    for (int i = minNum; i <= maxNum; i++) {
      if (!freq2[i])
        continue;

      int len = 0, num = i, count = get_count(num);
      while (count > 1) {
        len++;
        num *= num;
        count = get_count(num);
      }

      maxLen = max(maxLen, 2 * (len + count) - 1);
    }

    return maxLen;
  }
};

int main() {
  Solution sol;
  {
    vector<int> arr = {5, 4, 1, 2, 2};
    assert(sol.maximumLength(arr) == 3);
  }
  {
    vector<int> arr = {1, 3, 2, 4};
    assert(sol.maximumLength(arr) == 1);
  }
  {
    vector<int> arr = {1, 1, 1, 1, 1};
    assert(sol.maximumLength(arr) == 5);
  }
  {
    vector<int> arr = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    assert(sol.maximumLength(arr) == 9);
  }
  {
    vector<int> arr = {30000, 30000, 900000000, 900000000};
    assert(sol.maximumLength(arr) == 3);
  }
  return 0;
}
