#include <cstring>
#include <iostream>

using namespace std;

long long cache[69];

long long fib(int n) {
  if (n < 2) return 1;
  if (n == 2) return 2;
  if (n == 3) return 4;

  long long& ret = cache[n];
  if (ret != -1) return ret;

  return ret = fib(n - 1) + fib(n - 2) + fib(n - 3) + fib(n - 4);
}

int main(void) {
  int t, n;
  memset(cache, -1, sizeof(cache));

  cin >> t;

  while (t--) {
    cin >> n;
    cout << fib(n) << '\n';
  }
}
