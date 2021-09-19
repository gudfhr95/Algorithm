#include <cstring>
#include <iostream>

using namespace std;

int cache[1000001];

int make(int n) {
  if (n == 0) return -1;
  if (n == 1) return 0;

  if (cache[n] != -1) return cache[n];

  int &ret = cache[n];

  return ret = min(make(n / 3) + 1 + (n % 3), make(n / 2) + 1 + (n % 2));
}

int main() {
  int N;

  memset(cache, -1, sizeof(cache));

  cin >> N;

  cout << make(N);
}