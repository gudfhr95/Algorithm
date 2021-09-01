#include <cstring>
#include <iostream>

using namespace std;

int triangle[500][500];
int cache[500][500];
int n;

int findBiggestPath(int y, int x) {
  if (y == n - 1) return triangle[y][x];

  int &ret = cache[y][x];

  if (ret != -1) return ret;

  return ret = max(findBiggestPath(y + 1, x), findBiggestPath(y + 1, x + 1)) +
               triangle[y][x];
}

int main() {
  cin >> n;

  memset(cache, -1, sizeof(cache));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      cin >> triangle[i][j];
    }
  }

  cout << findBiggestPath(0, 0);
}