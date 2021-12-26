#include <cstdio>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int inf = 1000000000;

int a[20][20];
int b[20][20];
int d[20][20 * 9];
bool check[20][20 * 9];

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;

      scanf(" %c", &c);

      if (c != '.') {
        a[i][j] = c - '0';
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;

      scanf(" %c", &c);

      if (c != '.') {
        b[i][j] = c - '0';
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n * 9; j++) {
      d[i][j] = inf;
    }
  }

  priority_queue<tuple<int, int, int>> q;

  d[0][0] = 0;
  q.push(make_tuple(0, 0, 0));

  while (!q.empty()) {
    auto p = q.top();
    q.pop();

    int x = get<1>(p);
    int dist = get<2>(p);

    if (check[x][dist]) {
      continue;
    }

    check[x][dist] = true;

    for (int i = 0; i < n; i++) {
      int y = i;

      if (a[x][y] == 0) continue;

      int d1 = d[x][dist] + a[x][y];
      int d2 = dist + b[x][y];

      if (d2 >= n * 9) continue;

      if (d[y][d2] > d1) {
        d[y][d2] = d1;
        q.push(make_tuple(-d[y][d2], y, d2));
      }
    }
  }

  int ans = inf;
  for (int i = 0; i < n * 9; i++) {
    if (check[1][i] == false) continue;

    ans = min(ans, d[1][i] * i);
  }

  if (ans == inf) ans = -1;

  printf("%d", ans);
}