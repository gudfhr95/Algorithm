#include <iostream>

using namespace std;

int mod = 10007;

int d[1001][1001];

int main() {
  int N, K;

  cin >> N >> K;

  d[0][0] = d[1][0] = d[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    d[i][0] = d[i][i] = 1;

    for (int j = 1; j < i; j++) {
      d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
      d[i][j] %= mod;
    }
  }

  cout << d[N][K];
}