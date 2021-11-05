#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
int map[1000][1000];
int dist[1000][1000][2];

void bfs(int x, int y) {
  queue<tuple<int, int, int>> q;

  q.push({x, y, 0});
  dist[0][0][0] = 1;

  int xc, yc, zc, xn, yn;
  while (!q.empty()) {
    tie(xc, yc, zc) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];

      if (xn < 0 || yn < 0 || xn >= M || yn >= N) continue;

      if (map[yn][xn] == 0 && dist[yn][xn][zc] == 0) {
        q.push({xn, yn, zc});
        dist[yn][xn][zc] = dist[yc][xc][zc] + 1;
      }

      if (zc == 0 && map[yn][xn] == 1 && dist[yn][xn][zc + 1] == 0) {
        q.push({xn, yn, zc + 1});
        dist[yn][xn][zc + 1] = dist[yc][xc][zc] + 1;
      }
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      scanf("%1d", &map[y][x]);
    }
  }

  bfs(0, 0);

  if (dist[N - 1][M - 1][0] != 0 && dist[N - 1][M - 1][1] != 0) {
    cout << min(dist[N - 1][M - 1][0], dist[N - 1][M - 1][1]);
  } else if (dist[N - 1][M - 1][0] != 0) {
    cout << dist[N - 1][M - 1][0];
  } else if (dist[N - 1][M - 1][1] != 0) {
    cout << dist[N - 1][M - 1][1];
  } else {
    cout << -1;
  }
}