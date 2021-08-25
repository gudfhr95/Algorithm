#include <iostream>

using namespace std;

int BOARD[3][3] = {
    0,
};

int checkRightDiagonal() {
  if (BOARD[0][2] == BOARD[1][1] && BOARD[1][1] == BOARD[2][0])
    return BOARD[0][2];
  else
    return 0;
}

int checkLeftDiagonal() {
  if (BOARD[0][0] == BOARD[1][1] && BOARD[1][1] == BOARD[2][2])
    return BOARD[0][0];
  else
    return 0;
}

int checkColumn(int x) {
  if (BOARD[0][x] == BOARD[1][x] && BOARD[1][x] == BOARD[2][x])
    return BOARD[0][x];
  else
    return 0;
}

int checkRow(int y) {
  if (BOARD[y][0] == BOARD[y][1] && BOARD[y][1] == BOARD[y][2])
    return BOARD[y][0];
  else
    return 0;
}

int checkWinner() {
  int winner = 0;

  for (int i = 0; i < 3; i++) {
    winner = checkRow(i);
    if (winner) return winner;
  }

  for (int i = 0; i < 3; i++) {
    winner = checkColumn(i);
    if (winner) return winner;
  }

  winner = checkLeftDiagonal();
  if (winner) return winner;

  winner = checkRightDiagonal();
  if (winner) return winner;

  return 0;
}

int main() {
  int player, x, y;

  cin >> player;

  int winner = 0;
  for (int i = 0; i < 9; i++) {
    cin >> y >> x;

    player = player % 2;
    if (player == 0) player = 2;

    BOARD[y - 1][x - 1] = player;

    winner = checkWinner();
    if (winner) {
      cout << winner;
      break;
    }

    player++;
  }

  if (!winner) {
    cout << 0;
  }
}