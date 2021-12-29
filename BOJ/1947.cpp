#include <iostream>

using namespace std;

long long d[1000001];
const long long mod = 1000000000;

int main() {
  int n;

  cin >> n;

  d[1] = 0;
  d[2] = 1;
  for (int i = 3; i <= n; i++) {
    d[i] = (i - 1) * (d[i - 1] + d[i - 2]);
    d[i] %= mod;
  }

  cout << d[n] << '\n';

  return 0;
}
