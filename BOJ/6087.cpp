#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int W, H;
char map[100][101];
int dist[100][100];

void bfs(int x, int y) {
  queue<pair<int, int>> q;

  q.push({x, y});
  dist[y][x] = 0;

  int xc, yc, xn, yn;
  while (!q.empty()) {
    tie(xc, yc) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];
      while (true) {
        if (xn < 0 || yn < 0 || xn > W - 1 || yn > H - 1) break;

        if (map[yn][xn] == '*') break;

        if (dist[yn][xn] == -1) {
          q.push({xn, yn});
          dist[yn][xn] = dist[yc][xc] + 1;
        }

        xn += dx[k];
        yn += dy[k];
      }
    }
  }
}

int main() {
  cin >> W >> H;

  int xs, ys, xe, ye;
  xs = ys = xe = ye = -1;
  for (int y = 0; y < H; y++) {
    cin >> map[y];

    for (int x = 0; x < W; x++) {
      if (map[y][x] == 'C') {
        if (xs == -1 && ys == -1) {
          xs = x;
          ys = y;
        } else {
          xe = x;
          ye = y;
        }
      }
    }
  }

  memset(dist, -1, sizeof(dist));
  bfs(xs, ys);

  cout << dist[ye][xe] - 1;
}