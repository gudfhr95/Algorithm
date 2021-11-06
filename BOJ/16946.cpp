#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
int map[1000][1000];

int color[1000][1000];
int cnt[1000000];

void bfs(int x, int y, int c) {
  queue<pair<int, int>> q;

  int n = 1;
  q.push({x, y});
  color[y][x] = c;

  int xc, yc, xn, yn;
  while (!q.empty()) {
    tie(xc, yc) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];

      if (xn < 0 || yn < 0 || xn >= M || yn >= N) continue;

      if (map[yn][xn] == 0 && color[yn][xn] == 0) {
        q.push({xn, yn});
        color[yn][xn] = c;
        n++;
      }
    }
  }

  cnt[c] = n;
}

int main() {
  scanf("%d %d", &N, &M);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      scanf("%1d", &map[y][x]);
      color[y][x] = 0;
    }
  }

  int c = 1;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (map[y][x] == 0 && color[y][x] == 0) {
        bfs(x, y, c++);
      }
    }
  }

  // for (int y = 0; y < N; y++) {
  //   for (int x = 0; x < M; x++) {
  //     cout << color[y][x] << ' ';
  //   }
  //   cout << '\n';
  // }

  // for (int i = 1; i < c; i++) {
  //   cout << cnt[i] << ' ';
  // }
  // cout << '\n';

  int result[N][M];
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (map[y][x] == 0) {
        result[y][x] = 0;
      } else {
        set<int> adj;
        for (int k = 0; k < 4; k++) {
          int xn = x + dx[k];
          int yn = y + dy[k];

          if (xn < 0 || yn < 0 || xn >= M || yn >= N) continue;

          if (map[yn][xn] == 1) continue;

          adj.insert(color[yn][xn]);
        }

        int sum = 1;
        for (int c : adj) {
          sum += cnt[c];
          sum %= 10;
        }
        result[y][x] = sum;
      }
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cout << result[y][x];
    }
    cout << '\n';
  }
}