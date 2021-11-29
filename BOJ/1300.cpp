#include <iostream>

using namespace std;

int main() {
  long long N, k;

  cin >> N >> k;

  long long l = 1;
  long long r = N * N;
  long long result = 0;

  while (l <= r) {
    long long mid = (l + r) / 2;
    long long cnt = 0;
    for (long long i = 1; i <= N; i++) {
      cnt += min(N, mid / i);
    }

    if (cnt >= k) {
      result = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << result;
}