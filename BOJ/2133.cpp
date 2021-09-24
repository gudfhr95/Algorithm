#include <cstring>
#include <iostream>

using namespace std;

int cache[31];

int block(int n) {
  if (n % 2 == 1) return 0;
  if (n == 0) return 1;

  if (cache[n] != -1) return cache[n];

  int &ret = cache[n];

  ret = 3 * block(n - 2);
  for (int i = 4; i <= n; i += 2) {
    ret += 2 * block(n - i);
  }
  return ret;
}

int main() {
  int N;

  memset(cache, -1, sizeof(cache));

  cin >> N;

  cout << block(N);
}