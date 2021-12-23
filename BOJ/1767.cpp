#include <cstring>
#include <iostream>

using namespace std;

int N, M, K;
long long d[101][101][101];

long long go(int n, int m, int k) {
  if (k == 0) {
    return 1;
  }

  if (n <= 0 || m <= 0 || k < 0) {
    return 0;
  }

  long long &ret = d[n][m][k];

  if (d[n][m][k] != -1) return ret;

  ret = go(n - 1, m, k) + go(n - 1, m - 1, k - 1) * m +
        go(n - 1, m - 2, k - 2) * m * (m - 1) / 2 +
        go(n - 2, m - 1, k - 2) * m * (n - 1);
  ret %= 1000001;

  return ret;
}

int main() {
  cin >> N >> M >> K;

  memset(d, -1, sizeof(d));

  cout << go(N, M, K);
}