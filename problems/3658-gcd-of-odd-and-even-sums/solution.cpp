class Solution {
public:
  int gcdOfOddEvenSums(int n) {
    int sumOdd = n * n;
    int sumEven = n * (n + 1);

    while (sumOdd != 0) {
      int r = sumEven % sumOdd;
      sumEven = sumOdd;
      sumOdd = r;
    }

    return sumEven;
  }
};
