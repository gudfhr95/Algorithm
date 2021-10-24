#include <iostream>

using namespace std;

int N;
int result = 0;
bool board[15][15];

bool check(int x, int y) {
  for (int i = 0; i < N; i++) {
    if (i == y) continue;

    if (board[i][x]) return false;
  }

  int y1 = y - 1;
  int x1 = x - 1;
  while (x1 >= 0 && y1 >= 0) {
    if (board[y1][x1]) return false;

    y1--;
    x1--;
  }

  y1 = y - 1;
  x1 = x + 1;
  while (y1 >= 0 && x1 < N) {
    if (board[y1][x1]) return false;

    y1--;
    x1++;
  }

  return true;
}

void queen(int y) {
  if (y == N) {
    result += 1;
  }

  for (int x = 0; x < N; x++) {
    board[y][x] = true;
    if (check(x, y)) {
      queen(y + 1);
    }
    board[y][x] = false;
  }
}

int main() {
  cin >> N;

  queen(0);

  cout << result;
}