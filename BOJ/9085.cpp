#include <iostream>

using namespace std;

int main() {
  int T, N, n, sum;

  cin >> T;

  while (T--) {
    cin >> N;

    sum = 0;
    for (int i = 0; i < N; i++) {
      cin >> n;
      sum += n;
    }

    cout << sum << '\n';
  }
}