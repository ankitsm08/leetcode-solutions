#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool match(const char open, const char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}')
           || (open == '[' && close == ']');
  }

  bool isValid(string s) {
    if (s.size() & 1)
      return false;

    stack<char> stack;

    for (const char ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        stack.push(ch);
      } else {
        if (stack.empty())
          return false;
        const char pop = stack.top();
        if (!match(pop, ch))
          return false;
        stack.pop();
      }
    }

    if (!stack.empty())
      return false;

    return true;
  }
};
