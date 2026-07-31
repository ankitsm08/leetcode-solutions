#include <algorithm>
#include <array>
#include <functional>
#include <string>

using namespace std;

class Solution {
public:
  int minimumPushes(const string &word) {
    array<int, 26> freq{};
    for (const char c : word)
      freq[c - 'a']++;

    for (int i = 0; i < 26 / 8; i++)
      nth_element(freq.begin() + i * 8, freq.begin() + (i + 1) * 8 - 1, freq.end(), greater<>());

    int count = 0;
    for (int i = 0; i < 26; i++)
      count += (i / 8 + 1) * freq[i];

    return count;
  }
};
