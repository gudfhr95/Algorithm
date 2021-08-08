#include <iostream>

using namespace std;

int main() {
  int T, N, K, n, result;

  cin >> T;

  while (T--) {
    cin >> N >> K;

    result = 0;

    for (int i = 0; i < N; i++) {
      cin >> n;
      result += n / K;
    }

    cout << result << '\n';
  }
}