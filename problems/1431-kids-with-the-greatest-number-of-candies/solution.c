#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *kidsWithCandies(int *candies, int candiesSize, int extraCandies,
                      int *returnSize) {
  int max = 0;
  for (int i = 0; i < candiesSize; i++)
    if (candies[i] > max)
      max = candies[i];

  bool *result = malloc(candiesSize * sizeof(bool));
  *returnSize = candiesSize;

  for (int i = 0; i < candiesSize; i++)
    result[i] = candies[i] >= max - extraCandies;

  return result;
}
