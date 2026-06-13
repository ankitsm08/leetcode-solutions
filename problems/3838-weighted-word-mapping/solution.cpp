#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string mapWordWeights(vector<string> &words, vector<int> &weights) {
    string answer;
    answer.reserve(words.size());

    for (const string &word : words) {
      int weight = 0;
      for (const char &ch : word) {
        weight += weights[ch - 'a'];
      }
      answer.push_back('z' - (weight % 26));
    }

    return answer;
  }
};
