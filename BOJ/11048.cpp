#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

int cache[1000][1000];
int candy[1000][1000];
int N, M;

int getMaxCandy(int y, int x) {
  if (y > N - 1 || y < 0 || x > M - 1 || x < 0) return 0;

  int &ret = cache[y][x];

  if (ret != -1) return ret;

  ret = max({candy[y][x] + getMaxCandy(y + 1, x),
             candy[y][x] + getMaxCandy(y, x + 1),
             candy[y][x] + getMaxCandy(y + 1, x + 1)});

  return ret;
}

int main() {
  cin >> N >> M;

  memset(cache, -1, sizeof(cache));
  memset(candy, -1, sizeof(candy));

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> candy[y][x];
    }
  }

  cout << getMaxCandy(0, 0);
}