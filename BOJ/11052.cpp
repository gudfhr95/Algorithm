#include <cstring>
#include <iostream>

using namespace std;

int cache[1001];
int price[10001];

int buy(int n) {
  if (cache[n] != -1) return cache[n];

  int &ret = cache[n];

  ret = price[n];
  for (int i = 1; i <= n; i++) {
    int p = price[i] + buy(n - i);
    ret = max(ret, p);
  }

  return ret;
}

int main() {
  int N;

  cin >> N;

  memset(cache, -1, sizeof(cache));

  for (int i = 1; i <= N; i++) {
    cin >> price[i];
  }

  cout << buy(N);
}