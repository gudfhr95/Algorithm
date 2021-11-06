#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M, K;
int map[1000][1000];
int dist[1000][1000][11][2];

void bfs(int x, int y) {
  queue<tuple<int, int, int, bool>> q;

  q.push({x, y, 0, 0});
  dist[y][x][0][0] = 1;

  int xc, yc, z, d, xn, yn;
  while (!q.empty()) {
    tie(xc, yc, z, d) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];

      if (xn < 0 || yn < 0 || xn > M - 1 || yn > N - 1) continue;

      if (d == 0) {
        if (map[yn][xn] == 0 && dist[yn][xn][z][d + 1] == -1) {
          q.push({xn, yn, z, d + 1});
          dist[yn][xn][z][d + 1] = dist[yc][xc][z][d] + 1;
        }
        if (z < K && map[yn][xn] == 1 && dist[yn][xn][z + 1][d + 1] == -1) {
          q.push({xn, yn, z + 1, d + 1});
          dist[yn][xn][z + 1][d + 1] = dist[yc][xc][z][d] + 1;
        }
      } else if (d == 1) {
        if (map[yn][xn] == 0 && dist[yn][xn][z][d - 1] == -1) {
          q.push({xn, yn, z, d - 1});
          dist[yn][xn][z][d - 1] = dist[yc][xc][z][d] + 1;
        }
        if (map[yn][xn] == 1 && dist[yc][xc][z][d - 1] == -1) {
          q.push({xc, yc, z, d - 1});
          dist[yc][xc][z][d - 1] = dist[yc][xc][z][d] + 1;
        }
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
    for (int d = 0; d < 2; d++) {
      int res = dist[N - 1][M - 1][k][d];

      if (result == -1 && res != -1) {
        result = res;
      } else if (result != -1 && res != -1) {
        result = min(result, res);
      }
    }
  }

  cout << result;
}