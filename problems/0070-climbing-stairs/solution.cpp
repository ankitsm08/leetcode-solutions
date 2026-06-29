class Solution {
public:
  int climbStairs(int n) {
    if (n < 3)
      return n;

    int s1 = 1, s2 = 2;
    for (int i = 2; i < n; i++) {
      const int s3 = s1 + s2;
      s1 = s2;
      s2 = s3;
    }

    return s2;
  }
};
