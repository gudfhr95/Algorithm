#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int d[51][51][4][4];

int main() {
  int n, m;

  cin >> n >> m;

  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = -1;
  int x1, y1, x2, y2;
  x1 = y1 = x2 = y2 = -1;

  memset(d, -1, sizeof(d));

  queue<tuple<int, int, int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'S') {
        for (int k = 0; k < 4; k++) {
          q.push(make_tuple(i, j, k, 0));
          d[i][j][k][0] = 0;
        }
      } else if (a[i][j] == 'C') {
        if (x1 == -1) {
          x1 = i;
          y1 = j;
        } else {
          x2 = i;
          x2 = j;
        }
      }
    }
  }

  while (!q.empty()) {
    int x, y, dir, s;
    tie(x, y, dir, s) = q.front();
    q.pop();

    if (s == 3) {
      ans = d[x][y][dir][s];
      break;
    }

    for (int k = 0; k < 4; k++) {
      if (dir == k) continue;

      int nx = x + dx[k];
      int ny = y + dy[k];
      if (0 <= nx && nx < n && 0 <= ny && ny < m) {
        if (a[nx][ny] != '#') {
          int ns = s;
          if (a[nx][ny] == 'C') {
            if (nx == x1 && ny == y1) {
              ns |= 1;
            } else {
              ns |= 2;
            }
          }

          if (d[nx][ny][k][ns] == -1) {
            d[nx][ny][k][ns] = d[x][y][dir][s] + 1;
            q.push(make_tuple(nx, ny, k, ns));
          }
        }
      }
    }
  }

  cout << ans << '\n';

  return 0;
}
