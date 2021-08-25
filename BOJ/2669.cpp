#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int x1, y1, x2, y2;
  int board[100][100] = {
      0,
  };

  for (int i = 0; i < 4; i++) {
    cin >> x1 >> y1 >> x2 >> y2;

    for (int y = y1; y < y2; y++) {
      for (int x = x1; x < x2; x++) {
        board[y][x] = 1;
      }
    }
  }

  int result = 0;
  for (int y = 0; y < 100; y++) {
    for (int x = 0; x < 100; x++) {
      if (board[y][x]) result++;
    }
  }

  cout << result;
}