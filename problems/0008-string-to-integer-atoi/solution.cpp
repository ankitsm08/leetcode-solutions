#include <cctype>
#include <climits>
#include <string>

using namespace std;

class Solution {
public:
  int myAtoi(string s) {
    int num = 0;
    bool positive = true;
    const size_t n = s.length();
    size_t i = 0;

    while (i < n && s[i] == ' ')
      i++;

    if (i < n && (s[i] == '-' || s[i] == '+'))
      positive = s[i++] == '+';

    if (positive) {
      while (i < n && isdigit(s[i])) {
        const int digit = s[i++] - '0';

        if (num > INT_MAX / 10 || (num == INT_MAX / 10 && digit > INT_MAX % 10))
          return INT_MAX;

        num = num * 10 + digit;
      }
    } else {
      while (i < n && isdigit(s[i])) {
        const int digit = -(s[i++] - '0');

        if (num < INT_MIN / 10 || (num == INT_MIN / 10 && digit < INT_MIN % 10))
          return INT_MIN;

        num = num * 10 + digit;
      }
    }

    return num;
  }
};
