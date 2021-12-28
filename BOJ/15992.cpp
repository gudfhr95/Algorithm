#include <stdio.h>

long long d[1001][1001];

const long long mod = 1000000009LL;
const int limit = 1000;

int main() {
  d[0][0] = 1;

  for (int i = 1; i <= limit; i++) {
    for (int j = 1; j <= i; j++) {
      if (i - 1 >= 0) {
        d[i][j] += d[i - 1][j - 1];
      }

      if (i - 2 >= 0) {
        d[i][j] += d[i - 2][j - 1];
      }

      if (i - 3 >= 0) {
        d[i][j] += d[i - 3][j - 1];
      }

      d[i][j] %= mod;
    }
  }

  int t;

  scanf("%d", &t);

  while (t--) {
    int n, m;

    scanf("%d %d", &n, &m);

    long long ans = 0;

    ans = d[n][m];
    ans %= mod;

    printf("%lld\n", ans);
  }
}