#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> cellsInRange(string s) {
    const char c1 = s[0], c2 = s[3];
    const char r1 = s[1], r2 = s[4];
    const size_t rows = static_cast<size_t>(r2 - r1 + 1);
    const size_t cols = static_cast<size_t>(c2 - c1 + 1);
    vector<string> cells;
    cells.reserve(rows * cols);

    for (char c = c1; c <= c2; c++) {
      for (char r = r1; r <= r2; r++) {
        cells.push_back({c, r});
      }
    }

    return cells;
  }
};
