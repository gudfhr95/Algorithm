#include <cstring>
#include <iostream>

using namespace std;

int COINS[4] = {25, 10, 5, 1};

int main() {
  int T, C;
  int result[4];

  cin >> T;

  while (T--) {
    cin >> C;

    memset(result, 0, sizeof(result));

    for (int i = 0; i < 4; i++) {
      result[i] += C / COINS[i];
      C %= COINS[i];
    }

    for (int i = 0; i < 4; i++) {
      cout << result[i] << ' ';
    }
    cout << '\n';
  }
}