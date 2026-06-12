#include <limits.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

int minimumSum(int num) {
  int digit_count = 0;
  int copy = num;

  while (copy > 0) {
    digit_count++;
    copy /= 10;
  }

  int *digits = malloc(digit_count * sizeof(int));

  copy = num;
  for (int i = 0; i < digit_count; i++) {
    digits[i] = copy % 10;
    copy /= 10;
  }

  int min1 = 0, min2 = 0;
  qsort(digits, digit_count, sizeof(int), cmp);

  for (int i = 0; i < digit_count / 2; i++) {
    min1 = min1 * 10 + digits[2 * i];
    min2 = min2 * 10 + digits[2 * i + 1];
  }
  if (digit_count & 1)
    min1 = min1 * 10 + digits[digit_count / 2 + 1];

  return min1 + min2;
}
