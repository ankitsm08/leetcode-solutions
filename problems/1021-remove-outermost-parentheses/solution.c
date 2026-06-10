#include <stdlib.h>

char *removeOuterParentheses(char *s) {
  int depth = 0;
  int count = 0;

  int i = 0;
  while (*(s + i)) {
    if (depth > 0)
      count++;

    if (*(s + i) == '(')
      depth++;
    else
      count -= --depth == 0;
    i++;
  }

  char *s_rem = malloc(count + 1);

  int idx = 0;
  i = 0;
  while (*(s + i)) {
    if (depth > 0)
      s_rem[idx++] = *(s + i);

    if (*(s + i) == '(')
      depth++;
    else {
      idx -= --depth == 0;
    }
    i++;
  }

  s_rem[count] = '\0';
  return s_rem;
}
