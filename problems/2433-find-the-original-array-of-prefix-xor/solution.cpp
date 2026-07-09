#include <utility>
#include <vector>

class Solution {
public:
  std::vector<int> findArray(std::vector<int> &pref) {
    for (size_t i = pref.size() - 1; i > 0; i--)
      pref[i] ^= pref[i - 1];
    return std::move(pref);
  }
};
