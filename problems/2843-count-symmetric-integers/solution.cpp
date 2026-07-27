#include <algorithm>
#include <array>

using namespace std;

class Solution {
  static constexpr int N = []() {
    int count = 0;

    for (int i = 10; i <= 99; ++i)
      count += (i / 10 == i % 10);

    for (int i = 1000; i <= 9999; ++i) {
      const int sum_first = (i / 1000) + ((i / 100) % 10);
      const int sum_second = ((i / 10) % 10) + (i % 10);
      count += sum_first == sum_second;
    }

    return count;
  }();

  static constexpr auto symmetric_lookup = []() {
    array<int, N> arr{};
    int idx = 0;

    for (int i = 10; i <= 99; ++i) {
      if (i / 10 == i % 10)
        arr[idx++] = i;
    }

    for (int i = 1000; i <= 9999; ++i) {
      const int sum_first = (i / 1000) + ((i / 100) % 10);
      const int sum_second = ((i / 10) % 10) + (i % 10);
      if (sum_first == sum_second)
        arr[idx++] = i;
    }

    return arr;
  }();

public:
  int countSymmetricIntegers(int l, int h) {
    const auto lcount = lower_bound(symmetric_lookup.begin(), symmetric_lookup.end(), l);
    const auto rcount = upper_bound(symmetric_lookup.begin(), symmetric_lookup.end(), h);
    return static_cast<int>(rcount - lcount);
  }
};
