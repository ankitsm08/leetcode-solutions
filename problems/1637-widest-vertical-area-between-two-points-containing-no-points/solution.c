#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

inline static int max_int(int a, int b) { return a > b ? a : b; }
inline static int min_int(int a, int b) { return a < b ? a : b; }

int maxWidthOfVerticalArea(int **points, int pointsSize, int *pointsColSize) {
  if (pointsSize < 2)
    return 0;
  (void)pointsColSize;

  int arr[pointsSize];

  int max = 0, min = INT_MAX;
  for (int i = 0; i < pointsSize; i++) {
    arr[i] = points[i][0];
    max = max_int(arr[i], max);
    min = min_int(arr[i], min);
  }

  int bucket_width = max_int(1, (max - min) / (pointsSize - 1));
  int bucket_count = (max - min) / bucket_width + 1;
  int bucket_min[bucket_count];
  int bucket_max[bucket_count];
  bool empty[bucket_count];

  for (int i = 0; i < bucket_count; i++) {
    bucket_min[i] = INT_MAX;
    bucket_max[i] = INT_MIN;
    empty[i] = true;
  }
  for (int i = 0; i < pointsSize; i++) {
    int bucket_index = (arr[i] - min) / bucket_width;
    bucket_min[bucket_index] = min_int(bucket_min[bucket_index], arr[i]);
    bucket_max[bucket_index] = max_int(bucket_max[bucket_index], arr[i]);
    empty[bucket_index] = false;
  }

  int max_width = 0;
  int last = -1;
  for (int i = 0; i < bucket_count; i++) {
    if (empty[i])
      continue;
    if (last != -1)
      max_width = max_int(bucket_min[i] - bucket_max[last], max_width);
    last = i;
  }

  return max_width;
}

int run(int pts[][2], int n) {
  int *points[n];
  for (int i = 0; i < n; i++)
    points[i] = pts[i];

  int colSize = 2;
  return maxWidthOfVerticalArea(points, n, &colSize);
}

int main() {
  {
    int array[][2] = {{8, 7}, {9, 9}, {7, 4}, {9, 7}};
    printf("{{8, 7}, {9, 9}, {7, 4}, {9, 7}} -> %d\n", run(array, 4));
    assert(run(array, 4) == 1);
  }
  {
    int array[][2] = {{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}};
    printf("{{3, 1}, {9, 0}, {1, 0}, {1, 4}, {5, 3}, {8, 8}} -> %d\n",
           run(array, 6));
    assert(run(array, 6) == 3);
  }
  {
    int array[][2] = {{1, 1}, {1, 2}, {1, 3}};
    printf("{{1, 1}, {1, 2}, {1, 3}} -> %d\n", run(array, 3));
    assert(run(array, 3) == 0);
  }
  {
    int array[][2] = {{0, 0}, {1000000000, 0}};
    printf("{{0, 0}, {1000000000, 0}} -> %d\n", run(array, 2));
    assert(run(array, 2) == 1000000000);
  }
}
