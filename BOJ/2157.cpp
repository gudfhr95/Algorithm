#include <iostream>

using namespace std;

int a[301][301];
int d[301][301];

int main() {
  ios_base::sync_with_stdio(false);

  int n, m, k;

  cin >> n >> m >> k;

  while (k--) {
    int x, y, z;

    cin >> x >> y >> z;

    if (a[x][y] < z) {
      a[x][y] = z;
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      d[i][j] = -1;
    }
  }

  d[1][1] = 0;
  for (int j = 1; j <= m - 1; j++) {
    for (int i = 1; i <= n; i++) {
      if (d[i][j] == -1) {
        continue;
      }

      for (int k = i + 1; k <= n; k++) {
        if (a[i][k] > 0) {
          d[k][j + 1] = max(d[k][j + 1], d[i][j] + a[i][k]);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 2; i <= m; i++) {
    ans = max(ans, d[n][i]);
  }

  cout << ans << '\n';

  return 0;
}
