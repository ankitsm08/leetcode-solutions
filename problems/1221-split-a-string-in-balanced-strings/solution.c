int balancedStringSplit(char *s) {
  int splits = 0;
  int r = 0, l = 0;
  while (*s) {
    if (*s == 'R')
      r++;
    else if (*s == 'L')
      l++;

    if (r == l) {
      splits++;
      r = l = 0;
    }

    s++;
  }

  return splits;
}
