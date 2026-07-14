#include <array>
#include <string>

using namespace std;

class Solution {
  static constexpr array<string_view, 13> roman = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                                   "XL", "X",  "IX", "V",  "IV", "I"};
  static constexpr array<int, 13> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

public:
  string intToRoman(int num) {
    string res;
    for (size_t i = 0; num > 0; i++) {
      while (num >= value[i]) {
        res.append(roman[i]);
        num -= value[i];
      }
    }
    return res;
  }
};
