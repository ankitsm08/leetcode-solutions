char *reversePrefix(char *s, int k) {
  for (int i = 0; i < k / 2; i++) {
    *(s + i) = *(s + i) + *(s + k - i - 1);
    *(s + k - i - 1) = *(s + i) - *(s + k - i - 1);
    *(s + i) = *(s + i) - *(s + k - i - 1);
  }
  return s;
}
