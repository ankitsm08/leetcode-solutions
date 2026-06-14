#include <queue>
#include <vector>

using namespace std;

using Node = pair<int, int>;
using MinHeap = priority_queue<Node, vector<Node>, greater<Node>>;

class Solution {
public:
  vector<int> getFinalState(vector<int> &nums, int k, int multiplier) {
    MinHeap pq;

    for (int i = 0; i < nums.size(); i++) {
      pq.push({nums[i], i});
    }

    while (k--) {
      auto [val, idx] = pq.top();
      pq.pop();
      pq.push({val * multiplier, idx});
    }

    while (!pq.empty()) {
      auto [val, idx] = pq.top();
      pq.pop();
      nums[idx] = val;
    }

    return nums;
  }
};
