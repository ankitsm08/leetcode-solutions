int finalValueAfterOperations(char **operations, int operationsSize) {
  int x = 0;
  for (int i = 0; i < operationsSize; i++) {
    x += 2 * (operations[i][1] == '+') - 1;
  }
  return x;
}
