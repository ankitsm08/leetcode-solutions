#include <vector>

using namespace std;

class Solution {
public:
  vector<int> mostCompetitive(vector<int> &nums, int k) {
    const int n = static_cast<int>(nums.size());

    vector<int> subseq;
    subseq.reserve(k);

    for (int i = 0; i < n; i++) {
      while (!subseq.empty() && static_cast<int>(subseq.size()) + n - i > k
             && subseq.back() > nums[i])
        subseq.pop_back();

      if (static_cast<int>(subseq.size()) < k)
        subseq.push_back(nums[i]);
    }

    return subseq;
  }
};
