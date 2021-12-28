#include <iostream>
#include <vector>

using namespace std;

const long long mod = 1000000007LL;

long long d[11][100001];
long long sum[11];
vector<int> divisors[100001];

int main() {
  int n, k;

  cin >> n >> k;

  for (int i = 1; i <= k; i++) {
    for (int j = i * 2; j <= k; j += i) {
      divisors[j].push_back(i);
    }
  }

  for (int j = 1; j <= k; j++) {
    d[1][j] = 1;
  }

  sum[1] = k;

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      d[i][j] = sum[i - 1];

      for (int div : divisors[j]) {
        d[i][j] -= d[i - 1][div];
        d[i][j] %= mod;
        d[i][j] += mod;
        d[i][j] %= mod;
      }

      sum[i] += d[i][j];
      sum[i] %= mod;
    }
  }

  cout << sum[n] << '\n';

  return 0;
}