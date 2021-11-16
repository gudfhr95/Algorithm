#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N, K;

  cin >> N >> K;

  for (int a = 0; a <= N; a++) {
    int b = N - a;

    if (a * b < K) continue;

    vector<int> cnt(b + 1);

    for (int i = 0; i < a; i++) {
      int x = min(b, K);
      cnt[x] += 1;
      K -= x;
    }

    for (int i = b; i >= 0; i--) {
      for (int j = 0; j < cnt[i]; j++) {
        cout << 'A';
      }
      if (i > 0) {
        cout << 'B';
      }
    }

    return 0;
  }

  cout << -1;
  return 0;
}