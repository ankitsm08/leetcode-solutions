#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // INFO: Solution using standard library method
  //
  // int numOfStrings(const vector<string> &patterns, const string &word) {
  //   int count = 0;
  //   for (const string &p : patterns) {
  //     count += static_cast<int>(word.find(p) != string::npos);
  //   }
  //   return count;
  // }

  // INFO: Knuth-Morris-Pratt Algorithm
  //
  int numOfStrings(const vector<string> &patterns, const string &word) {
    const size_t n = word.size();
    vector<size_t> lps(n, 0);
    int count = 0;

    for (const string &pattern : patterns) {
      const size_t m = pattern.size();
      if (m > n)
        continue;
      fill(lps.begin(), lps.begin() + m, 0);

      for (size_t i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
          j = lps[j - 1];
        if (pattern[i] == pattern[j])
          j++;
        lps[i] = j;
      }

      for (size_t i = 0, j = 0; i < n; i++) {
        while (j > 0 && word[i] != pattern[j])
          j = lps[j - 1];
        if (word[i] == pattern[j])
          j++;
        if (j == m) {
          count++;
          break;
        }
      }
    }

    return count;
  }
};
