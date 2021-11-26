#include <iostream>

using namespace std;

long long N, M;
long long T[1000000];

bool check(long long x) {
  long long result = 0;
  for (int i = 0; i < N; i++) {
    if (T[i] < x) continue;

    result += T[i] - x;
  }

  return result >= M;
}

int main() {
  cin >> N >> M;

  long long maxlen = 0;
  for (int i = 0; i < N; i++) {
    cin >> T[i];
    maxlen = max(maxlen, T[i]);
  }

  long long l = 1;
  long long r = maxlen;
  long long result = 0;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      result = max(result, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << result;
}