#include <iostream>

using namespace std;

int cnt[10001];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;

  cin >> N;

  for (int i = 0; i < N; i++) {
    int n;

    cin >> n;

    cnt[n]++;
  }

  for (int i = 1; i <= 10000; i++) {
    if (cnt[i] == 0) continue;

    for (int j = 0; j < cnt[i]; j++) {
      cout << i << '\n';
    }
  }
}