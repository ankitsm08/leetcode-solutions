#include <algorithm>
#include <cassert>
#include <cstddef>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  // INFO: Two Pointer
  //
  // string longestPalindrome(string s) {
  //   const size_t n = s.length();
  //   if (n < 2)
  //     return s;
  //
  //   bool even = false;
  //   size_t max_len_c = 0;
  //   size_t max_r = 0;
  //
  //   for (size_t c = 1; c < n - 1; c++) {
  //     size_t r = 1;
  //     // odd length
  //     while (c >= r && c + r <= n - 1 && s[c - r] == s[c + r]) {
  //       r++;
  //     }
  //
  //     if (max_r < --r) {
  //       max_len_c = c;
  //       max_r = r;
  //       even = false;
  //     }
  //
  //     r = 1;
  //     // even length
  //     while (c + 1 >= r && c + r <= n - 1 && s[c - r + 1] == s[c + r]) {
  //       r++;
  //     }
  //
  //     if (max_r < --r) {
  //       max_len_c = c;
  //       max_r = r;
  //       even = true;
  //     }
  //   }
  //
  //   return s.substr(max_len_c - max_r + even, 2 * max_r + 1 - even);
  // }

  // INFO: Manacher's Algorithm
  //
  string longestPalindrome(string s) {
    if (s.length() < 2)
      return s;

    string T;
    T.reserve(2 * s.size() + 3);

    T.append("^#");
    for (const char ch : s) {
      T.push_back(ch);
      T.push_back('#');
    }
    T.append("$");

    const size_t n = T.length();
    vector<size_t> P(n, 0);
    size_t C = 0, R = 0;

    for (size_t i = 1; i < n - 1; i++) {
      if (i < R) {
        const size_t mirror = 2 * C - i;
        P[i] = min(R - i, P[mirror]);
      }

      while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
        P[i]++;

      if (i + P[i] > R) {
        C = i;
        R = i + P[i];
      }
    }

    auto it = max_element(P.begin(), P.end());
    const size_t max_radius = *it;
    const size_t center = static_cast<size_t>(it - P.begin());
    const size_t start = (center - max_radius) >> 1;

    return s.substr(start, max_radius);
  }
};

int main() {
  Solution sol;
  assert(sol.longestPalindrome("babad") == "bab");
  assert(sol.longestPalindrome("cbbd") == "bb");
  assert(sol.longestPalindrome("abracadabraba") == "aca");
  assert(sol.longestPalindrome("abcdadcabacabebacabcadadcab") == "bacabebacab");
  return 0;
}
