#include <algorithm>
#include <iostream>

using namespace std;

int wine[10001];
int cache[10001][3];

int drink(int n) {
  cache[0][0] = 0;
  cache[0][1] = 0;
  cache[0][2] = 0;

  for (int i = 1; i <= n; i++) {
    cache[i][0] = max({cache[i - 1][0], cache[i - 1][1], cache[i - 1][2]});
    cache[i][1] = wine[i] + cache[i - 1][0];
    cache[i][2] = wine[i] + cache[i - 1][1];
  }

  return max({cache[n][0], cache[n][1], cache[n][2]});
}

int main() {
  int n;

  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> wine[i];
  }

  cout << drink(n);
}