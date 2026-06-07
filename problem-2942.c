#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findWordsContaining(char **words, int wordsSize, char x, int *returnSize) {
  int n = 0;
  int idxs[wordsSize];

  for (int i = 0; i < wordsSize; i++) {
    int j = 0;
    while (*words[i] != '\0') {
      if (*words[i] == x) {
        idxs[n++] = i;
        break;
      }
      words[i]++;
    }
  }

  int *indices = malloc(n * sizeof(int));
  *returnSize = n;
  for (int i = 0; i < n; i++) {
    indices[i] = idxs[i];
  }

  return indices;
}
