int numberOfEmployeesWhoMetTarget(int *hours, int hoursSize, int target) {
  int n = 0;
  for (int i = 0; i < hoursSize; i++) {
    n += hours[i] >= target;
  }
  return n;
}
