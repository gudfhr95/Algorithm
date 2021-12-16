#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
int board[1000][1000];
int color[1000][1000];
int cnt[1000000];

void bfs(int x, int y, int c) {
  int result = 1;

  queue<pair<int, int>> q;
  q.push({x, y});
  color[y][x] = c;

  int xc, yc, xn, yn;
  while (!q.empty()) {
    tie(xc, yc) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];

      if (xn < 0 || yn < 0 || xn > M - 1 || yn > N - 1) continue;

      if (board[yn][xn] == 0) continue;

      if (color[yn][xn] != -1) continue;

      q.push({xn, yn});
      color[yn][xn] = c;
      result++;
    }
  }

  cnt[c] = result;
}

int main() {
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> board[y][x];
    }
  }

  memset(color, -1, sizeof(color));

  int c = 1;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (board[y][x] == 1 && color[y][x] == -1) {
        bfs(x, y, c++);
      }
    }
  }

  int result = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (board[y][x] == 0) {
        int sum = 1;
        set<int> s;

        for (int k = 0; k < 4; k++) {
          int xn = x + dx[k];
          int yn = y + dy[k];

          if (xn < 0 || yn < 0 || xn > M - 1 || yn > N - 1) continue;

          if (color[yn][xn] == -1) continue;

          s.insert(color[yn][xn]);
        }

        for (int e : s) {
          sum += cnt[e];
        }

        result = max(result, sum);
      }
    }
  }

  cout << result;
}