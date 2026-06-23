#include <array>
#include <string>

using namespace std;

class Solution {
public:
  string sortSentence(string s) {
    constexpr size_t MAX_WORDS = 9;
    const size_t len = s.length();

    size_t wordCount = 0;
    array<pair<size_t, size_t>, MAX_WORDS> words;

    size_t start = 0;
    for (size_t i = 0; i < len; i++) {
      if (s[i] >= '1' && s[i] <= '9') {
        words[s[i] - '1'] = {start, i - start};
        start = i + 2;
        wordCount++;
      }
    }

    string ans;
    ans.reserve(len - wordCount);

    for (size_t i = 0; i < wordCount - 1; i++) {
      ans.append(s, words[i].first, words[i].second);
      ans.push_back(' ');
    }
    ans.append(s, words[wordCount - 1].first, words[wordCount - 1].second);

    return ans;
  }
};
