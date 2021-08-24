#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;
  int primes[1001] = {
      0,
  };

  cin >> N >> K;

  for (int i = 2; i <= N; i++) {
    primes[i] = 1;
  }

  int count = 0;
  for (int i = 2; i <= N; i++) {
    if (!primes[i]) continue;

    for (int j = 1; j <= N / i; j++) {
      if (primes[i * j]) {
        primes[i * j] = 0;
        count++;

        if (count == K) cout << i * j;
      }
    }
  }
}
