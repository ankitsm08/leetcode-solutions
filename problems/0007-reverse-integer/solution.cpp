#include <climits>
#include <iostream>

class Solution {
public:
  int reverse(int x) {
    int rev = 0;

    while (x != 0) {
      int digit = x % 10;
      x /= 10;

      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > INT_MAX % 10))
        return 0;

      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < INT_MIN % 10))
        return 0;

      rev = 10 * rev + digit;
    }

    return rev;
  }
};

int main() {
  Solution sol;
  std::cout << sol.reverse(123456) << std::endl;
  std::cout << sol.reverse(0) << std::endl;
  std::cout << sol.reverse(-1234) << std::endl;
  std::cout << sol.reverse(2147483646) << std::endl;
  std::cout << sol.reverse(-2147483647) << std::endl;
  std::cout << sol.reverse(-100) << std::endl;
  std::cout << sol.reverse(50800) << std::endl;
  std::cout << sol.reverse(1999999992) << std::endl;
  std::cout << sol.reverse(1999999312) << std::endl;
  return 0;
}
