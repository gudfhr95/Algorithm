#include <cstring>
#include <iostream>

using namespace std;

long long c[22][22];
long long d[22];

long long go(int n) {
  if (d[n] != -1) return d[n];

  long long &ans = d[n];

  ans = 0;
  for (int i = 1; i <= n; i += 2) {
    ans += c[n - 1][i - 1] * go(i - 1) * go(n - i);
  }

  return ans;
}
int main() {
  c[0][0] = 1;

  for (int i = 1; i <= 20; i++) {
    c[i][0] = c[i][i] = 1;

    for (int j = 1; j <= i - 1; j++) {
      c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
  }

  memset(d, -1, sizeof(d));

  d[0] = d[1] = d[2] = 1;

  int t;

  cin >> t;

  while (t--) {
    int n;

    cin >> n;

    if (n == 1) {
      cout << 1 << '\n';
    } else {
      cout << 2LL * go(n) << '\n';
    }
  }

  return 0;
}