#include <algorithm>
#include <iostream>

using namespace std;

int a[1002][1002];
int d[1002][1002][3];

const int inf = 100000000;

int main() {
  int n, m;

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  fill(&d[0][0][0], &d[1001][1001][2] + 1, -inf);

  d[1][1][1] = a[1][1];
  for (int j = 2; j <= m; j++) {
    d[1][j][1] = d[1][j - 1][1] + a[1][j];
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      d[i][j][0] =
          max({d[i - 1][j][0], d[i - 1][j][1], d[i - 1][j][2]}) + a[i][j];
      d[i][j][1] = max(d[i][j - 1][0], d[i][j - 1][1]) + a[i][j];
    }
    for (int j = m; j >= 1; j--) {
      d[i][j][2] = max(d[i][j + 1][0], d[i][j + 1][2]) + a[i][j];
    }
  }

  cout << max({d[n][m][0], d[n][m][1], d[n][m][2]}) << '\n';

  return 0;
}