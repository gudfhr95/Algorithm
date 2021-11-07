#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[9] = {0, 0, 1, 1, 1, 0, -1, -1, -1};
int dy[9] = {0, 1, 1, 0, -1, -1, -1, 0, 1};

char board[8][9];
bool visited[8][8][9];

void bfs() {
  queue<tuple<int, int, int>> q;

  q.push({0, 7, 0});
  visited[7][0][0] = true;

  int xc, yc, tc, xn, yn, tn;
  while (!q.empty()) {
    tie(xc, yc, tc) = q.front();
    q.pop();

    if (xc == 7 && yc == 0) {
      cout << 1;
      return;
    }

    for (int k = 0; k < 9; k++) {
      int xn = xc + dx[k];
      int yn = yc + dy[k];
      int tn = min(tc + 1, 8);

      if (xn < 0 || yn < 0 || xn > 7 || yn > 7) continue;

      if (yn - tc >= 0 && board[yn - tc][xn] == '#') continue;

      if (yn - tc - 1 >= 0 && board[yn - tc - 1][xn] == '#') continue;

      if (visited[yn][xn][tn]) continue;

      q.push({xn, yn, tn});
      visited[yn][xn][tn] = true;
    }
  }

  cout << 0;
  return;
}

int main() {
  for (int y = 0; y < 8; y++) {
    cin >> board[y];
  }

  bfs();
}