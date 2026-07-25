#include <bitset>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findMissingElements(vector<int> &nums) {
    constexpr int MAX_VAL = 100;

    int mx = nums.front(), mn = nums.front();
    bitset<MAX_VAL + 1> seen;

    for (int num : nums) {
      if (num > mx)
        mx = num;
      else if (num < mn)
        mn = num;
      seen.set(num);
    }

    vector<int> res;
    for (int i = mn + 1; i < mx; ++i) {
      if (!seen[i])
        res.push_back(i);
    }

    return res;
  }
};
