#include <cstring>
#include <iostream>

using namespace std;

int cache[1001];

int tile(int n) {
  if (n == 1) return 1;
  if (n == 2) return 3;

  if (cache[n] != -1) return cache[n];

  int &ret = cache[n];

  return ret = (tile(n - 1) + (2 * tile(n - 2))) % 10007;
}

int main() {
  int n;

  memset(cache, -1, sizeof(cache));

  cin >> n;

  cout << tile(n);
}