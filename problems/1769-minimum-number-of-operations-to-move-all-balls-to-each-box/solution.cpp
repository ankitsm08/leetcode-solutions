#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> minOperations(const string &boxes) {
    const int n = static_cast<int>(boxes.size());
    vector<int> answer(n, 0);

    int behind = (boxes[0] - '0');
    int ahead = -behind;
    for (int i = 0; i < n; i++) {
      const int num = boxes[i] - '0';
      answer[0] += i * num;
      ahead += num;
    }

    for (int i = 1; i < n; i++) {
      const int num = boxes[i] - '0';
      answer[i] += answer[i - 1] - ahead + behind;
      behind += num;
      ahead -= num;
    }

    return answer;
  }
};
