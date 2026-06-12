int countDigits(int num) {
  int copy = num, count = 0;
  while (copy > 0) {
    if (num % (copy % 10) == 0)
      count++;
    copy /= 10;
  }
  return count;
}
