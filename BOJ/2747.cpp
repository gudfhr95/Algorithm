#include <cstring>
#include <iostream>

using namespace std;

long cache[91];

long fib(int n) {
  if (n < 2) {
    return n;
  }

  long& ret = cache[n];
  if (ret != -1) return ret;

  return ret = (fib(n - 1) + fib(n - 2));
}

int main() {
  int n;
  memset(cache, -1, sizeof(cache));

  cin >> n;

  cout << fib(n);

  return 0;
}