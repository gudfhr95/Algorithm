#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int t, l, x_start, y_start, x_target, y_target;
int board[300][300];

void bfs(int x, int y) {
  queue<pair<int, int>> q;

  q.push({x, y});
  board[y][x] = 0;

  while (!q.empty()) {
    int x1 = q.front().first;
    int y1 = q.front().second;

    q.pop();

    for (int i = 0; i < 8; i++) {
      int x2 = x1 + dx[i];
      int y2 = y1 + dy[i];

      if (x2 < 0 || y2 < 0 || x2 > l - 1 || y2 > l - 1) continue;

      if (board[y2][x2] != -1) continue;

      q.push({x2, y2});
      board[y2][x2] = board[y1][x1] + 1;
    }
  }
}

int main() {
  cin >> t;

  while (t--) {
    cin >> l;

    cin >> x_start >> y_start >> x_target >> y_target;

    memset(board, -1, sizeof(board));

    bfs(x_start, y_start);

    cout << board[y_target][x_target] << '\n';
  }
}