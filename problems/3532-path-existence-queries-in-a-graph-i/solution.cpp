#include <vector>

using namespace std;

class Solution {
public:
  vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
                                    vector<vector<int>> &queries) {
    vector<int> component(n, 0);

    int curr_component = 0;
    for (int i = 1; i < n; i++) {
      curr_component += nums[i] - nums[i - 1] > maxDiff;
      component[i] = curr_component;
    }

    vector<bool> answer;
    answer.reserve(queries.size());

    for (const auto &query : queries)
      answer.push_back(component[query[0]] == component[query[1]]);

    return answer;
  }
};
