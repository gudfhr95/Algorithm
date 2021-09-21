#include <iostream>

using namespace std;

int cache[100001];

int squareSum(int n) {
  for (int i = 1; i <= n; i++) {
    cache[i] = i;
    for (int j = 1; j * j <= i; j++) {
      cache[i] = min(cache[i], cache[i - (j * j)] + 1);
    }
  }

  return cache[n];
}

int main() {
  int n;

  cin >> n;

  cout << squareSum(n);
}