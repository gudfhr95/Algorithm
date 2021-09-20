#include <cstring>
#include <iostream>

using namespace std;

int cache[12];

int sum(int n) {
  if (n == 1) return 1;
  if (n == 2) return 2;
  if (n == 3) return 4;

  if (cache[n] != -1) return cache[n];

  int &ret = cache[n];

  return ret = (sum(n - 1) + sum(n - 2) + sum(n - 3));
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