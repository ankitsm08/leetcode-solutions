#include <stdlib.h>

int findPermutationDifference(char *s, char *t) {
  int occS[26] = {0}, occT[26] = {0};
  for (int i = 0; *(s + i); i++) {
    occS[*(s + i) - 'a'] = i;
    occT[*(t + i) - 'a'] = i;
  }

  int diff = 0;
  for (int i = 0; i < 26; i++) {
    diff += abs(occS[i] - occT[i]);
  }

  return diff;
}
