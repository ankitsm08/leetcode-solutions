#include <stdio.h>

int fib(int n) {
  if (n < 3)
    return (int)(n > 0);

  int f1 = 1, f2 = 1;
  for (int i = 2; i < n; i++) {
    const int f3 = f1 + f2;
    f1 = f2;
    f2 = f3;
  }

  return f2;
}

int main(void) {
  printf("%d", fib(10));
  return 0;
}
