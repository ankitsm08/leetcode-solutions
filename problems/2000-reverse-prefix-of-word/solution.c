char *reversePrefix(char *word, char ch) {
  char *p0 = word;
  char *p1 = word;
  while (*p1) {
    if (*p1 == ch)
      break;
    p1++;
  }
  if (!*p1)
    return word;

  while (p0 < p1) {
    *p0 = *p1 + *p0;
    *p1 = *p0 - *p1;
    *p0 = *p0 - *p1;
    p0++;
    p1--;
  }

  return word;
}
