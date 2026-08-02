#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
  using ll = long long;
  static constexpr int MAX_TASKS = static_cast<int>(1e5);
  static inline vector<ll> prefix = vector<ll>(MAX_TASKS);

public:
  vector<int> countTasks(vector<int> &tasks, vector<int> &shifts) {
    const int n = static_cast<int>(tasks.size());
    const int m = static_cast<int>(shifts.size());
    prefix.resize(n);
    prefix[0] = tasks[0];
    for (int i = 1; i < n; ++i)
      prefix[i] = prefix[i - 1] + tasks[i];

    vector<int> ans;
    ans.reserve(m);
    ll prev = 0;
    for (int hours : shifts) {
      auto it = upper_bound(prefix.begin(), prefix.end(), prev + hours);
      const int left = static_cast<int>(distance(it, prefix.end()));

      ans.push_back(left);
      prev = left == 0 ? 0 : (prev + hours);
    }

    return ans;
  }
};
