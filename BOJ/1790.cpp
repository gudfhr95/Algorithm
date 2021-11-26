#include <cmath>
#include <iostream>

using namespace std;

int getLength(int n) {
  int result = 0;
  while (n > 0) {
    n /= 10;
    result++;
  }

  return result;
}

int main() {
  int N, k;

  cin >> N >> k;

  for (int i = 1; i <= N; i++) {
    k -= getLength(i);

    if (k == 0) {
      cout << i % 10;
      return 0;
    } else if (k < 0) {
      cout << (i / (int)pow(10, abs(k)) % 10);
      return 0;
    }
  }

  if (k > 0) {
    cout << -1;
  }
  return 0;
}