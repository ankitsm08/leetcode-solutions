#include <stdlib.h>

int findClosest(int x, int y, int z) {
  int dx = abs(z - x);
  int dy = abs(z - y);

  if (dx == dy)
    return 0;
  else if (dx < dy)
    return 1;
  else
    return 2;
}
