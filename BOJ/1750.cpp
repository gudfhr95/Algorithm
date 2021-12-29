#include <iostream>

using namespace std;

const int mod = 10000003;

int d[101][100001];
int a[101];

int gcd(int x, int y) {
  if (y == 0) {
    return x;
  } else {
    return gcd(y, x % y);
  }
}

int main() {
  int n;

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    d[i][a[i]] += 1;

    for (int j = 1; j <= 100000; j++) {
      if (d[i - 1][j] == 0) {
        continue;
      }

      d[i][j] += d[i - 1][j];
      d[i][j] %= mod;

      int g = gcd(j, a[i]);
      d[i][g] += d[i - 1][j];
      d[i][g] %= mod;
    }
  }

  cout << d[n][1] << '\n';

  return 0;
}