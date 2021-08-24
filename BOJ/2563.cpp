#include <iostream>

using namespace std;

int main() {
  int N, X, Y;
  int BOARD[100][100] = {
      0,
  };

  cin >> N;

  while (N--) {
    cin >> X >> Y;

    for (int y = Y; y < Y + 10; y++) {
      for (int x = X; x < X + 10; x++) {
        BOARD[y][x] = 1;
      }
    }
  }

  int result = 0;
  for (int y = 0; y < 100; y++) {
    for (int x = 0; x < 100; x++) {
      if (BOARD[y][x]) result++;
    }
  }

  cout << result;
}
