#include <iostream>

using namespace std;

int inf = 987654321;

int d[101][101];

int main() {
  int n, m;

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        d[i][j] = 0;
      } else {
        d[i][j] = inf;
      }
    }
  }

  int a, b, c;
  for (int i = 1; i <= m; i++) {
    cin >> a >> b >> c;

    if (d[a][b] > c) {
      d[a][b] = c;
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (d[i][j] == inf) {
        cout << 0 << ' ';
      } else {
        cout << d[i][j] << ' ';
      }
    }
    cout << '\n';
  }
}