#include <cstring>
#include <iostream>

using namespace std;

long long cache[1000001];

long long sum(int n) {
  if (n < 0) return 0;
  if (n == 0 || n == 1) return 1;

  if (cache[n] != -1) return cache[n];

  long long &ret = cache[n];

  return ret = (sum(n - 1) + sum(n - 2) + sum(n - 3)) % 1000000009;
}

int main() {
  int T, n;

  memset(cache, -1, sizeof(cache));

  cin >> T;

  while (T--) {
    cin >> n;

    cout << sum(n) << '\n';
  }
}