#include <cstring>
#include <iostream>

using namespace std;

int ROOM[101];

int main() {
  int T, n;

  cin >> T;

  while (T--) {
    cin >> n;

    memset(ROOM, 0, sizeof(ROOM));

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n / i; j++) {
        ROOM[i * j] = !ROOM[i * j];
      }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
      if (ROOM[i]) result++;
    }

    cout << result << '\n';
  }
}
