#include <array>
#include <ranges>
#include <string>
#include <string_view>

using namespace std;

class Solution {
  static constexpr array<string_view, 13> roman = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                                   "XL", "X",  "IX", "V",  "IV", "I"};
  static constexpr array<int, 13> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

public:
  int romanToInt(const string &s) {
    const string_view sv = s;

    int res = 0;
    for (size_t i = 0; i < sv.size(); i++) {
      for (const auto &[rom, val] : views::zip(roman, value)) {
        if (sv.substr(i, rom.size()) == rom) {
          res += val;
          i += rom.size() - 1;
          break;
        }
      }
    }

    return res;
  }
};
