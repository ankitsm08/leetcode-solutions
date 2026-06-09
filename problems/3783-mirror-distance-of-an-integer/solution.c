#include <stdlib.h>

int abs(int x) {
  if (x < 0)
    return -x;
  return x;
}

int reverse(int num) {
  int rev = 0, digit;
  while (num > 0) {
    digit = num % 10;
    rev = rev * 10 + digit;
    num /= 10;
  }
  return rev;
}

int mirrorDistance(int n) { return abs(reverse(n) - n); }
