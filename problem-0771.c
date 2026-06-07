int numJewelsInStones(char *jewels, char *stones) {
  int count = 0;
  while (*stones != '\0') {
    int i = 0;
    while (*(jewels + i) != '\0') {
      if (*stones == *(jewels + i)) {
        count++;
        break;
      }
      i++;
    }
    stones++;
  }
  return count;
}
