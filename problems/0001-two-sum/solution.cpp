#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // Sorting + 2 Pointer
  // vector<int> twoSum(vector<int> &nums, int target) {
  //   vector<pair<int, int>> numPairs;
  //   numPairs.reserve(nums.size());
  //
  //   for (int i = 0; i < nums.size(); i++) {
  //     numPairs.push_back({nums[i], i});
  //   }
  //
  //   sort(numPairs.begin(), numPairs.end(),
  //        [](auto &a, auto &b) { return a.first < b.first; });
  //
  //   int i = 0, j = nums.size() - 1;
  //   int value = numPairs[i].first + numPairs[j].first;
  //
  //   while (value != target) {
  //     if (value > target)
  //       j--;
  //     else if (value < target)
  //       i++;
  //     value = numPairs[i].first + numPairs[j].first;
  //   }
  //
  //   return {numPairs[i].second, numPairs[j].second};
  // }

  // Using Hash Map
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> seen;

    for (int i = 0; i < nums.size(); i++) {
      int compliment = target - nums[i];
      if (seen.count(compliment) > 0) {
        return {seen[compliment], i};
      }
      seen[nums[i]] = i;
    }

    return {};
  }
};
