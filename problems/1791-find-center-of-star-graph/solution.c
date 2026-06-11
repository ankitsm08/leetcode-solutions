int findCenter(int **edges, int edgesSize, int *edgesColSize) {
  int a = edges[0][0];
  int b = edges[0][1];
  int c = edges[1][0];
  int d = edges[1][1];

  if (a == c || a == d)
    return a;
  else
    return b;
}
