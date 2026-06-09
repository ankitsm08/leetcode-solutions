int reverseDegree(char *s) {
  int revDeg = 0, idx = 1;
  while (*s != '\0') {
    revDeg += ('z' - *s++ + 1) * idx++;
  }
  return revDeg;
}
