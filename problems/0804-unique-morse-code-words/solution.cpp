#include <array>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

static constexpr array<string_view, 26> morse = {
    ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
    ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
    "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

class Solution {
  static inline string morse_word;

public:
  int uniqueMorseRepresentations(vector<string> &words) {
    unordered_set<string> unique;

    for (const string &word : words) {
      morse_word.clear();

      for (const char c : word)
        morse_word.append(morse[c - 'a']);

      unique.insert(morse_word);
    }

    return static_cast<int>(unique.size());
  }
};

class TrieSolution {
  struct TrieNode {
    array<int, 2> children = {0, 0};
    bool is_end = false;
  };

  static inline vector<TrieNode> trie;

public:
  int uniqueMorseRepresentations(vector<string> &words) {
    trie.clear();
    trie.emplace_back();
    int unique_count = 0;

    for (const string &word : words) {
      int curr = 0;
      for (const char c : word) {
        for (const char m : morse[c - 'a']) {
          int bit = (m == '-');

          if (trie[curr].children[bit] == 0) {
            trie[curr].children[bit] = static_cast<int>(trie.size());
            trie.emplace_back();
          }
          curr = trie[curr].children[bit];
        }
      }

      if (!trie[curr].is_end) {
        trie[curr].is_end = true;
        unique_count++;
      }
    }

    return unique_count;
  }
};
