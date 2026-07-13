#include <algorithm>
#include <array>
#include <vector>

using namespace std;

class Solution {
  static constexpr int MAX_DIGIT_VAL = 9;
  static constexpr int MIN_LEN = 2;
  static constexpr int MAX_LEN = 9;
  static constexpr int POSSIBLE_ANSWERS = (MAX_LEN - MIN_LEN + 1) * MAX_LEN / 2;

  static constexpr array<int, POSSIBLE_ANSWERS> possible = []() {
    array<int, POSSIBLE_ANSWERS> arr{};
    size_t idx = 0;

    for (int len = MIN_LEN; len <= MAX_LEN; len++) {
      for (int start_digit = 1; start_digit <= MAX_DIGIT_VAL - len + 1; start_digit++) {
        int num = 0;
        for (int step = 0; step < len; step++) {
          num = num * 10 + start_digit + step;
        }
        arr[idx++] = num;
      }
    }

    return arr;
  }();

public:
  vector<int> sequentialDigits(int low, int high) {
    const auto begin = lower_bound(possible.begin(), possible.end(), low);
    const auto end = upper_bound(begin, possible.end(), high);
    return {begin, end};
  }
};
