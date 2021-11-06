#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M, K;
int map[1000][1000];
int dist[1000][1000][11];

void bfs(int x, int y) {
  queue<tuple<int, int, int>> q;

  q.push({x, y, 0});
  dist[y][x][0] = 1;

  int xc, yc, z, xn, yn;
  while (!q.empty()) {
    tie(xc, yc, z) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];

      if (xn < 0 || yn < 0 || xn > M - 1 || yn > N - 1) continue;

      if (map[yn][xn] == 0 && dist[yn][xn][z] == -1) {
        q.push({xn, yn, z});
        dist[yn][xn][z] = dist[yc][xc][z] + 1;
      }

      if (z < K && map[yn][xn] == 1 && dist[yn][xn][z + 1] == -1) {
        q.push({xn, yn, z + 1});
        dist[yn][xn][z + 1] = dist[yc][xc][z] + 1;
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &N, &M, &K);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      scanf("%1d", &map[y][x]);
    }
  }

  memset(dist, -1, sizeof(dist));
  bfs(0, 0);

  int result = -1;
  for (int k = 0; k <= K; k++) {
    int res = dist[N - 1][M - 1][k];

    if (result == -1 && res != -1) {
      result = res;
    } else if (result != -1 && res != -1) {
      result = min(result, res);
    }
  }

  cout << result;
}