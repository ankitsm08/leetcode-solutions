class Solution {
public:
  int sumOfTheDigitsOfHarshadNumber(int x) {
    int digitSum = 0;
    for (int n = x; n > 0; n /= 10)
      digitSum += n % 10;
    return x % digitSum == 0 ? digitSum : -1;
  }
};
