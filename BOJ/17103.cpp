#include <cstring>
#include <iostream>
#include <set>

using namespace std;

bool isPrime[1000001];

void getPrime() {
  memset(isPrime, true, sizeof(isPrime));

  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i]) {
      for (int j = i * 2; j <= 1000000; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T, N;
  getPrime();

  cin >> T;

  while (T--) {
    cin >> N;

    set<pair<int, int>> result;
    for (int i = 2; i <= N / 2; i++) {
      if (isPrime[i] && isPrime[N - i]) {
        int a = min(i, N - i);
        int b = max(i, N - i);
        result.insert({a, b});
      }
    }

    cout << result.size() << '\n';
  }
}