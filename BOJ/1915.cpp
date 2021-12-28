#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int a[1001][1001];
int d[1001][1001];

int main() {
  int n, m;

  scanf("%d %d", &n, &m);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%1d", &a[i][j]);
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 0) {
        continue;
      }

      d[i][j] = min({d[i - 1][j - 1], d[i - 1][j], d[i][j - 1]}) + 1;

      if (ans < d[i][j]) {
        ans = d[i][j];
      }
    }
  }

  cout << ans * ans << '\n';

  return 0;
}
