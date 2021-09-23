#include <cstring>
#include <iostream>

using namespace std;

int cache[1001][10];

int increase(int n) {
  for (int i = 0; i < 10; i++) {
    cache[1][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k <= j; k++) {
        cache[i][j] += cache[i - 1][k];
        cache[i][j] %= 10007;
      }
    }
  }

  int result = 0;
  for (int i = 0; i < 10; i++) {
    result += cache[n][i];
    result %= 10007;
  }
  return result;
}

int main() {
  int N;

  memset(cache, 0, sizeof(cache));

  cin >> N;

  cout << increase(N);
}