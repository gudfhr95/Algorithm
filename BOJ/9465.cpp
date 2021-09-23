#include <algorithm>
#include <iostream>

using namespace std;

int sticker[2][100000];
int cache[3][100000];

int score(int n) {
  cache[0][0] = sticker[0][0];
  cache[1][0] = sticker[1][0];
  cache[2][0] = 0;

  for (int i = 1; i < n; i++) {
    cache[0][i] = sticker[0][i] + max(cache[1][i - 1], cache[2][i - 1]);
    cache[1][i] = sticker[1][i] + max(cache[0][i - 1], cache[2][i - 1]);
    cache[2][i] = max({cache[0][i - 1], cache[1][i - 1], cache[2][i - 1]});
  }

  return max({cache[0][n - 1], cache[1][n - 1], cache[2][n - 1]});
}

int main() {
  int T, n;

  cin >> T;

  while (T--) {
    cin >> n;

    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> sticker[i][j];
      }
    }

    cout << score(n) << '\n';
  }
}