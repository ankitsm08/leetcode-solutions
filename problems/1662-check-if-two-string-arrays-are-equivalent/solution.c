#include <stdbool.h>

bool arrayStringsAreEqual(char **word1, int word1Size, char **word2,
                          int word2Size) {
  int i1 = 0, i2 = 0;
  while (i1 < word1Size && i2 < word2Size) {
    if (*(*word1)++ != *(*word2)++) {
      return false;
    }
    if (!**word1) {
      word1++;
      i1++;
    }
    if (!**word2) {
      word2++;
      i2++;
    }
  }

  return i1 == word1Size && i2 == word2Size;
}
