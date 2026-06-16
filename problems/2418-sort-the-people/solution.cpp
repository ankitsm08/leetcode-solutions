#include <algorithm>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
    vector<size_t> idx(names.size(), 0);
    iota(idx.begin(), idx.end(), 0);

    sort(idx.begin(), idx.end(),
         [&heights](size_t i, size_t j) { return heights[i] > heights[j]; });

    vector<string> sorted_names;
    sorted_names.reserve(names.size());

    for (size_t i : idx) {
      sorted_names.push_back(names[i]);
    }

    return sorted_names;
  }
};
