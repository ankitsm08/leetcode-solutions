#include <algorithm>
#include <cstddef>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  // INFO: Stack
  //
  // int longestValidParentheses(string s) {
  //   stack<int> stack;
  //   stack.push(-1);
  //
  //   int maxlen = 0;
  //   for (int i = 0; (size_t)i < s.length(); i++) {
  //     if (s[(size_t)i] == '(') {
  //       stack.push(i);
  //     } else {
  //       stack.pop();
  //       if (stack.empty()) {
  //         stack.push(i);
  //       } else {
  //         maxlen = max(i - stack.top(), maxlen);
  //       }
  //     }
  //   }
  //
  //   return maxlen;
  // }

  // INFO: Two Pass
  //
  int longestValidParentheses(string s) {
    int maxlen = 0;

    int left = 0, right = 0;

    for (const char ch : s) {
      if (ch == '(')
        left++;
      else
        right++;

      if (left == right)
        maxlen = max(maxlen, 2 * right);
      else if (right > left)
        left = right = 0;
    }

    left = 0, right = 0;

    for (size_t i = s.size(); i-- > 0;) {
      if (s[i] == ')')
        right++;
      else
        left++;

      if (left == right)
        maxlen = max(maxlen, 2 * left);
      else if (left > right)
        left = right = 0;
    }

    return maxlen;
  }
};
