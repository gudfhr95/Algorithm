#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int dx[6] = {-2, -2, 0, 0, 2, 2};
int dy[6] = {-1, 1, -2, 2, -1, 1};

int N;
int board[200][200];

void bfs(int x, int y) {
  queue<pair<int, int>> q;

  q.push({x, y});
  board[y][x] = 0;

  while (!q.empty()) {
    pair<int, int> current = q.front();
    q.pop();

    for (int i = 0; i < 6; i++) {
      int nx = current.first + dx[i];
      int ny = current.second + dy[i];

      if (nx < 0 || ny < 0 || nx > N - 1 || ny > N - 1) continue;

      if (board[ny][nx] != -1) continue;

      q.push({nx, ny});
      board[ny][nx] = board[current.second][current.first] + 1;
    }
  }
}

int main() {
  cin >> N;

  int r1, c1, r2, c2;

  cin >> r1 >> c1 >> r2 >> c2;

  memset(board, -1, sizeof(board));
  bfs(r1, c1);

  cout << board[c2][r2];
}