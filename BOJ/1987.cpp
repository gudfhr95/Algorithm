#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int R, C;
char board[21][21];
bool alphabet[26];
int result = 1;

bool canMove(int x, int y) { return 0 <= x && x < C && 0 <= y && y < R; }

int go(int x, int y, int count) {
  if (count == 0) {
    alphabet[board[y][x] - 'A'] = true;
    count = 1;
  }

  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];

    if (!canMove(nx, ny)) continue;

    if (!alphabet[board[ny][nx] - 'A']) {
      alphabet[board[ny][nx] - 'A'] = true;
      int res = go(nx, ny, count + 1);
      result = max(result, res);
      alphabet[board[ny][nx] - 'A'] = false;
    }
  }

  return count;
}

int main() {
  cin >> R >> C;

  for (int i = 0; i < R; i++) {
    cin >> board[i];
  }

  go(0, 0, 0);

  cout << result;
}