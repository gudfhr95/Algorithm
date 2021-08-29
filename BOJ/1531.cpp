#include <iostream>

using namespace std;

int main() {
  int N, M, x1, y1, x2, y2;
  int BOARD[101][101] = {
      0,
  };

  cin >> N >> M;

  while (N--) {
    cin >> x1 >> y1 >> x2 >> y2;

    for (int y = y1; y <= y2; y++) {
      for (int x = x1; x <= x2; x++) {
        BOARD[y][x]++;
      }
    }
  }

  int result = 0;
  for (int y = 0; y <= 100; y++) {
    for (int x = 0; x <= 100; x++) {
      if (BOARD[y][x] > M) result++;
    }
  }

  cout << result;
}