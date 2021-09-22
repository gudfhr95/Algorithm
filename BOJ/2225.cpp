#include <iostream>

using namespace std;

int cache[201][201];

int sum(int k, int n) {
  for (int a = 1; a <= k; a++) {
    for (int b = 0; b <= n; b++) {
      for (int c = 0; c <= b; c++) {
        cache[a][b] += cache[a - 1][b - c];
        cache[a][b] %= 1000000000;
      }
    }
  }

  return cache[k][n];
}

int main() {
  int N, K;

  cache[0][0] = 1;

  cin >> N >> K;

  cout << sum(K, N);
}