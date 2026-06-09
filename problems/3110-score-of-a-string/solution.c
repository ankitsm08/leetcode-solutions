#include <stdlib.h>

int abs(int x) {
  if (x < 0)
    return -x;
  return x;
}

int scoreOfString(char *s) {
  int score = 0;
  while (*(s + 1) != '\0') {
    score += abs(*s - *(s + 1));
    s++;
  }
  return score;
}
