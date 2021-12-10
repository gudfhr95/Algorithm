#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
int board[20][20];
bool visited[20][20];

int bfs(int x, int y) {
  queue<pair<int, int>> q;

  q.push({x, y});
  visited[y][x] = true;

  bool dead = true;
  int result = 0;
  int xc, yc, xn, yn;
  while (!q.empty()) {
    result++;

    tie(xc, yc) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];

      if (xn < 0 || yn < 0 || xn > M - 1 || yn > N - 1) continue;

      if (board[yn][xn] == 0) {
        dead = false;
      } else if (board[yn][xn] == 2 && !visited[yn][xn]) {
        q.push({xn, yn});
        visited[yn][xn] = true;
      }
    }
  }

  return dead ? result : 0;
}

int go() {
  int result = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (board[y][x] == 2 && !visited[y][x]) result += bfs(x, y);
    }
  }

  return result;
}

int main() {
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> board[y][x];
    }
  }

  int result = 0;
  for (int i = 0; i < N * M; i++) {
    for (int j = 0; j < N * M; j++) {
      int xi = i % M;
      int yi = i / M;
      int xj = j % M;
      int yj = j / M;

      if (board[yi][xi] != 0 || board[yj][xj] != 0) continue;

      board[yi][xi] = 1;
      board[yj][xj] = 1;

      memset(visited, false, sizeof(visited));
      result = max(result, go());

      board[yi][xi] = 0;
      board[yj][xj] = 0;
    }
  }

  cout << result;
}
