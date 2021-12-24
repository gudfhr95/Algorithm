#include <iostream>

using namespace std;

bool d[1000001];

int main() {
  long long N, M;

  cin >> N >> M;

  for (long long i = 2; i * i <= M; i++) {
    long long p = i * i;

    long long start = N + (p - (N % p));
    if (start == N + p) start = N;

    for (long long j = start; j <= M; j += p) {
      d[j - N] = true;
    }
  }

  int result = 0;
  for (long long j = N; j <= M; j++) {
    if (!d[j - N]) {
      result++;
    }
  }

  cout << result;
}
