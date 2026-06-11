char *truncateSentence(char *s, int k) {
  char *p = s;
  while (*p && k > 0) {
    k -= *p++ == ' ';
  }
  if (*p != '\0')
    *(p - 1) = '\0';
  return s;
}
