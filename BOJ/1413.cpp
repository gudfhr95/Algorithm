#include <iostream>

using namespace std;

long long d[21][21];

long long gcd(long long x, long long y) { return y == 0 ? x : gcd(y, x % y); }

int main() {
  int N, M;

  cin >> N >> M;

  d[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= i; j++) {
      d[i][j] = d[i - 1][j - 1] + (i - 1) * d[i - 1][j];
    }
  }

  long long num = 0;
  for (int i = 1; i <= M; i++) {
    num += d[N][i];
  }

  long long denom = 1;
  for(int i=1; i<=N; i++){
    denom *= i;
  }

  long long g = gcd(num, denom);

  num /= g;
  denom /= g;

  cout << num << '/' << denom << '\n';
}
