#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *decode(int *encoded, int encodedSize, int first, int *returnSize) {
  int *arr = malloc((encodedSize + 1) * sizeof(int));
  *returnSize = encodedSize + 1;

  arr[0] = first;
  for (int i = 1; i < encodedSize + 1; i++) {
    arr[i] = encoded[i - 1] ^ arr[i - 1];
  }

  return arr;
}
