#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[12] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1};
int dy[12] = {1, 0, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2};
int dc[12] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1};

int K, W, H;
int map[200][200];
int dist[200][200][31];

void bfs() {
  queue<tuple<int, int, int>> q;

  q.push({0, 0, 0});
  dist[0][0][0] = 0;

  int xc, yc, cc, xn, yn, cn;
  while (!q.empty()) {
    tie(xc, yc, cc) = q.front();
    q.pop();

    for (int k = 0; k < 12; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];
      cn = cc + dc[k];

      if (xn < 0 || yn < 0 || xn > W - 1 || yn > H - 1) continue;

      if (map[yn][xn] == 1) continue;

      if (dist[yn][xn][cn] != -1) continue;

      if (cn > K) continue;

      q.push({xn, yn, cn});
      dist[yn][xn][cn] = dist[yc][xc][cc] + 1;
    }
  }
}

int main() {
  cin >> K >> W >> H;

  for (int y = 0; y < H; y++) {
    for (int x = 0; x < W; x++) {
      cin >> map[y][x];
    }
  }

  memset(dist, -1, sizeof(dist));
  bfs();

  int result = -1;
  for (int k = 0; k <= K; k++) {
    if (result == -1 && dist[H - 1][W - 1][k] != -1) {
      result = dist[H - 1][W - 1][k];
    } else if (dist[H - 1][W - 1][k] != -1) {
      result = min(result, dist[H - 1][W - 1][k]);
    }
  }

  cout << result;
}