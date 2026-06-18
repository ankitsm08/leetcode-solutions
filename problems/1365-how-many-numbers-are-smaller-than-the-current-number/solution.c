#include <stdlib.h>

typedef struct {
  int value;
  int index;
} Pair;

int cmp(const void *a, const void *b) { return (((Pair *)a)->value - ((Pair *)b)->value); }

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *smallerNumbersThanCurrent(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;

  Pair *arr = malloc(numsSize * sizeof(Pair));
  for (int i = 0; i < numsSize; i++) {
    arr[i].value = nums[i];
    arr[i].index = i;
  }

  qsort(arr, numsSize, sizeof(Pair), cmp);

  int *ans = malloc(numsSize * sizeof(int));

  int prev_count = 0;
  ans[arr[0].index] = 0;
  for (int i = 1; i < numsSize; i++) {
    if (arr[i].value == arr[i - 1].value) {
      ans[arr[i].index] = prev_count;
    } else {
      prev_count = i;
      ans[arr[i].index] = i;
    }
  }

  free(arr);
  return ans;
}
