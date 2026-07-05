#include <string>

using namespace std;

class Solution {
public:
  int minPartitions(string &n) {
    int max_digit = 0;
    for (char &ch : n) {
      const int digit = ch - '0';
      if (max_digit < digit) {
        if ((max_digit = digit) == 9)
          return max_digit;
      }
    }
    return max_digit;
  }
};
