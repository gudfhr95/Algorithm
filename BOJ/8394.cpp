#include <cstring>
#include <iostream>

using namespace std;

int cache[10000001];

int fibonacci(int n) {
  if (n <= 2) return n;

  int &ret = cache[n];

  if (ret != -1) return ret;

  return ret = (fibonacci(n - 1) + fibonacci(n - 2)) % 10;
}

int main() {
  int n;

  cin >> n;

  memset(cache, -1, sizeof(cache));

  for (int i = 1; i <= 10000000; i++) {
    fibonacci(i);
  }

  cout << fibonacci(n);
}