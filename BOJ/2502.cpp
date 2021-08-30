#include <iostream>

using namespace std;

int D, K;

int fibonacci(int n) {
  if (n <= 2) return 1;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

void getResult(int m1, int m2) {
  for (int i = 0; i <= K / m2; i++) {
    for (int j = 0; j <= K - (m2 * i); j++) {
      if ((m2 * i) + (m1 * j) == K) {
        cout << i << '\n';
        cout << j;
        return;
      }
    }
  }
}

int main() {
  cin >> D >> K;

  int m1 = fibonacci(D - 1);
  int m2 = fibonacci(D - 2);

  getResult(m1, m2);
}
