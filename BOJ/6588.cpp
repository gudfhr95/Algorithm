#include <iostream>

using namespace std;

int primes[1000001] = {
    0,
};

void getPrimeNumbers() {
  for (int i = 2; i <= 1000000; i++) {
    primes[i] = 1;
  }

  for (int i = 2; i <= 1000000; i++) {
    if (!primes[i]) continue;

    for (int j = 2; j <= 1000000 / i; j++) {
      primes[i * j] = 0;
    }
  }
}

int main() {
  int n;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  getPrimeNumbers();

  while (true) {
    cin >> n;

    if (n == 0) break;

    for (int i = 3; i <= 1000000; i++) {
      if (!primes[i]) continue;

      int remainder = n - i;
      if (primes[remainder]) {
        printf("%d = %d + %d\n", n, i, remainder);
        break;
      }
    }
  }
}
