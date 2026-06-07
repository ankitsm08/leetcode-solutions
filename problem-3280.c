#include <stdlib.h>
char *convertDateToBinary(char *date) {
  int ymd[3] = {0};

  for (int i = 0; i < 4; i++)
    ymd[0] = ymd[0] * 10 + date[i] - '0';
  for (int i = 5; i < 7; i++)
    ymd[1] = ymd[1] * 10 + date[i] - '0';
  for (int i = 8; i < 10; i++)
    ymd[2] = ymd[2] * 10 + date[i] - '0';

  int ymdLen = 0;
  for (int i = 0; i < 3; i++) {
    int num = ymd[i];
    while (num > 0) {
      ymdLen++;
      num >>= 1;
    }
  }

  char *ans = malloc(ymdLen + 2 + 1);

  int idx = ymdLen + 1;
  for (int i = 2; i >= 0; i--) {
    int num = ymd[i];
    while (num > 0) {
      ans[idx--] = '0' + (num % 2 != 0);
      num >>= 1;
    }
    if (idx >= 0)
      ans[idx--] = '-';
  }

  ans[ymdLen + 2] = '\0';
  return ans;
}
