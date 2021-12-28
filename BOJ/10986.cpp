#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, M;

  cin >> N >> M;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    a[i] %= M;
  }

  vector<long long> cnt(M, 0);
  cnt[0] = 1;

  int sum = 0;
  for (int i = 0; i < N; i++) {
    sum += a[i];
    sum %= M;
    cnt[sum] += 1;
  }

  long long result = 0;
  for (int i = 0; i < M; i++) {
    result += (long long)cnt[i] * (long long)(cnt[i] - 1) / 2LL;
  }

  cout << result;
}