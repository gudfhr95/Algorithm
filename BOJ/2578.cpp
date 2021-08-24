#include <iostream>

using namespace std;

int BOARD[5][5];

bool checkRightDiagnoal() {
  for (int x = 0; x < 5; x++) {
    if (BOARD[4 - x][x] != 0) return false;
  }
  return true;
}

bool checkLeftDiagonal() {
  for (int y = 0; y < 5; y++) {
    if (BOARD[y][y] != 0) return false;
  }
  return true;
}

bool checkColumn(int x) {
  for (int y = 0; y < 5; y++) {
    if (BOARD[y][x] != 0) return false;
  }
  return true;
}

bool checkRow(int y) {
  for (int x = 0; x < 5; x++) {
    if (BOARD[y][x] != 0) return false;
  }
  return true;
}

bool checkBingo() {
  int count = 0;

  for (int y = 0; y < 5; y++) {
    if (checkRow(y)) count++;
  }
  for (int x = 0; x < 5; x++) {
    if (checkColumn(x)) count++;
  }

  if (checkLeftDiagonal()) count++;
  if (checkRightDiagnoal()) count++;

  if (count >= 3)
    return true;
  else
    return false;
}

void erase(int n) {
  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      if (BOARD[y][x] == n) BOARD[y][x] = 0;
    }
  }
}

int main() {
  int n;

  for (int y = 0; y < 5; y++) {
    for (int x = 0; x < 5; x++) {
      cin >> n;
      BOARD[y][x] = n;
    }
  }

  for (int i = 0; i < 25; i++) {
    cin >> n;
    erase(n);
    if (checkBingo()) {
      cout << i + 1;
      break;
    }
  }
}
