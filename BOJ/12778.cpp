#include <iostream>

using namespace std;

int main() {
  int T, M, n;
  char C, c;

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;

  while (T--) {
    cin >> M >> C;

    if (C == 'C') {
      for (int i = 0; i < M; i++) {
        cin >> c;
        cout << (int)(c - 'A' + 1) << ' ';
      }
    } else if (C == 'N') {
      for (int i = 0; i < M; i++) {
        cin >> n;
        cout << (char)(n + 'A' - 1) << ' ';
      }
    }

    cout << '\n';
  }
}
