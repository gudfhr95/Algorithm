#include <iostream>

using namespace std;

int main() {
  int N, a, b, w, h;
  int board[1001][1001] = {
      0,
  };

  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> a >> b >> w >> h;

    for (int y = b; y < b + h; y++) {
      for (int x = a; x < a + w; x++) {
        board[y][x] = i;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    int result = 0;
    for (int y = 0; y < 1001; y++) {
      for (int x = 0; x < 1001; x++) {
        if (board[y][x] == i) result++;
      }
    }

    cout << result << '\n';
  }
}