#include <stdbool.h>

int countConsistentStrings(char *allowed, char **words, int wordsSize) {
  unsigned int mask = 0;

  while (*allowed != '\0') {
    mask |= 1u << (*allowed++ - 'a');
  }

  int count = wordsSize;
  for (int i = 0; i < wordsSize; i++) {
    while (*words[i] != '\0') {
      bool bit = (mask >> (*words[i]++ - 'a')) & 1;
      if (!bit) {
        count--;
        break;
      }
    }
  }

  return count;
}
