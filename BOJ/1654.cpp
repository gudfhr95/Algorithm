#include <iostream>

using namespace std;

int N, K;
long long W[10000];

bool check(long long x) {
  int result = 0;
  for (int i = 0; i < N; i++) {
    result += W[i] / x;
  }

  return result >= K;
}

int main() {
  cin >> N >> K;

  long long max = 0;
  for (int i = 0; i < N; i++) {
    cin >> W[i];
    if (W[i] > max) {
      max = W[i];
    }
  }

  long long result = 0;
  long long l = 1;
  long long r = max;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (check(mid)) {
      if (result < mid) {
        result = mid;
      }
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << result;
}