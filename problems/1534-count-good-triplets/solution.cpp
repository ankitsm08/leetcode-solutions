#include <cstdlib>
#include <vector>

using namespace std;

#define MAX_RANGE 1000
#define MIN_RANGE 0

class Solution {
public:
  // INFO: Naive Solution
  //
  // int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
  //   int n = arr.size();
  //   int count = 0;
  //
  //   for (int i = 0; i < n; i++) {
  //     for (int j = i + 1; j < n; j++) {
  //       for (int k = j + 1; k < n; k++) {
  //         if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b &&
  //             abs(arr[k] - arr[i]) <= c)
  //           count++;
  //       }
  //     }
  //   }
  //
  //   return count;
  // }

  // INFO: Exploiting the small constraints
  //
  int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
    const int n = arr.size();
    int count = 0;

    vector<int> sum(MAX_RANGE + 1, 0);

    for (int j = 0; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (abs(arr[j] - arr[k]) <= b) {
          int left = max(MIN_RANGE, max(arr[j] - a, arr[k] - c));
          int right = min(MAX_RANGE, min(arr[j] + a, arr[k] + c));

          if (right >= left) {
            if (left == MIN_RANGE) {
              count += sum[right];
            } else {
              count += sum[right] - sum[left - 1];
            }
          }
        }
      }
      for (int i = arr[j]; i <= MAX_RANGE; i++) {
        sum[i]++;
      }
    }

    return count;
  }
};
