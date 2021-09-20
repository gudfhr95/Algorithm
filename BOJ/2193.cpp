#include <cstring>
#include <iostream>

using namespace std;

long long cache[91][2];

void pinary(int n) {
  for (int i = 2; i <= n; i++) {
    cache[i][0] = cache[i - 1][0] + cache[i - 1][1];
    cache[i][1] = cache[i - 1][0];
  }
}

int main() {
  memset(cache, -1, sizeof(cache));

  cache[1][0] = 1;
  cache[1][1] = 1;

  int N;

  cin >> N;

  pinary(N);

  cout << cache[N][1];
}