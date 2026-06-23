#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome(const string &word) {
    const size_t n = word.length();
    for (size_t i = 0; i < n / 2; i++) {
      if (word[i] != word[n - 1 - i])
        return false;
    }
    return true;
  }

  string firstPalindrome(vector<string> &words) {
    for (const string &word : words) {
      if (isPalindrome(word))
        return word;
    }

    return "";
  }
};
