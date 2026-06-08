#include <assert.h>

int xorOperation(int n, int start) {
  int ret = 0, new_start = start >> 1, new_n = n;

  if (new_start & 1) {
    ret ^= --new_start;
    new_n = n + 1;
  }
  ret ^= (new_n >> 1) & 1;
  if (new_n & 1)
    ret ^= new_start + new_n - 1;

  ret = (ret << 1) + (n & start & 1);

  return ret;
}

int main() {
  assert(xorOperation(5, 0) == 8);
  assert(xorOperation(4, 3) == 8);
}
