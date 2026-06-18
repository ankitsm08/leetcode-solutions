#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *recoverOrder(int *order, int orderSize, int *friends, int friendsSize, int *returnSize) {
  int *orderFriends = (int *)malloc(friendsSize * sizeof(int));
  size_t idx = 0;

  for (size_t i = 0; i < orderSize; i++) {
    for (size_t j = 0; j < friendsSize; j++) {
      if (order[i] == friends[j]) {
        orderFriends[idx] = order[i];
        idx++;
        continue;
      }
    }
  }

  *returnSize = friendsSize;
  return orderFriends;
}
