#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> flipAndInvertImage(vector<vector<int>> &image) {
    const size_t n = image.size();
    const size_t nby2 = (n + 1) >> 1;
    for (vector<int> &row : image) {
      for (size_t j = 0; j < nby2; j++) {
        int inv = row[j] == 0;
        row[j] = row[n - 1 - j] == 0;
        row[n - 1 - j] = inv;
      }
    }
    return image;
  }
};
