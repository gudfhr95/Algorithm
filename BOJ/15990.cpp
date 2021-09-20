#include <cstring>
#include <iostream>

using namespace std;

long long cache[100001][3];

void sum(int n) {
  for (int i = 4; i <= n; i++) {
    cache[i][0] = (cache[i - 1][1] + cache[i - 1][2]) % 1000000009;
    cache[i][1] = (cache[i - 2][0] + cache[i - 2][2]) % 1000000009;
    cache[i][2] = (cache[i - 3][0] + cache[i - 3][1]) % 1000000009;
  }
}

int main() {
  int T, n;

  memset(cache, -1, sizeof(cache));

  cache[1][0] = 1;
  cache[1][1] = 0;
  cache[1][2] = 0;

  cache[2][0] = 0;
  cache[2][1] = 1;
  cache[2][2] = 0;

  cache[3][0] = 1;
  cache[3][1] = 1;
  cache[3][2] = 1;

  cin >> T;

  while (T--) {
    cin >> n;
    sum(n);
    cout << (cache[n][0] + cache[n][1] + cache[n][2]) % 1000000009 << '\n';
  }
}