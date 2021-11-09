#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N;
char pic[100][101];
int area[100][100][2];

void bfs(int x, int y, char color, int cnt, int blind) {
  queue<pair<int, int>> q;

  q.push({x, y});
  area[y][x][blind] = cnt;

  int xc, yc, xn, yn;
  while (!q.empty()) {
    tie(xc, yc) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];

      if (xn < 0 || yn < 0 || xn > N - 1 || yn > N - 1) continue;

      if (area[yn][xn][blind] != 0) continue;

      if (blind == 0) {
        if (pic[yn][xn] != color) continue;
      } else if (blind == 1) {
        if ((color == 'R' || color == 'G') && pic[yn][xn] == 'B') continue;
        if (color == 'B' && pic[yn][xn] != color) continue;
      }

      q.push({xn, yn});
      area[yn][xn][blind] = cnt;
    }
  }
}

int main() {
  cin >> N;

  for (int y = 0; y < N; y++) {
    cin >> pic[y];
  }

  int cnt1 = 1;
  int cnt2 = 1;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (area[y][x][0] == 0) {
        bfs(x, y, pic[y][x], cnt1++, 0);
      }

      if (area[y][x][1] == 0) {
        bfs(x, y, pic[y][x], cnt2++, 1);
      }
    }
  }

  cout << cnt1 - 1 << ' ' << cnt2 - 1;
}