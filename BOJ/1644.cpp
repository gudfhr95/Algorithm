#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

bool isPrime[4000001];

int main() {
  int N;

  cin >> N;

  if (N == 1) {
    cout << 0;
    return 0;
  }

  memset(isPrime, true, sizeof(isPrime));
  for (int i = 2; i <= 4000000; i++) {
    if (isPrime[i]) {
      for (int j = i * 2; j <= 4000000; j += i) {
        isPrime[j] = false;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i <= 4000000; i++) {
    if (isPrime[i]) {
      primes.push_back(i);
    }
  }

  int result = 0;

  int l = 0;
  int r = 0;
  int sum = primes[0];
  while (l <= r && r < primes.size()) {
    if (sum == N) {
      result++;
      sum += primes[++r];
    } else if (sum < N) {
      sum += primes[++r];
    } else {
      sum -= primes[l++];
    }
  }

  cout << result;
}