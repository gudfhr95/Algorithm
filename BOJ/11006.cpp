#include <iostream>

using namespace std;

int main() {
  int T, N, M;

  cin >> T;

  while (T--) {
    cin >> N >> M;

    cout << 2 * M - N << ' ' << N - M << '\n';
  }
}