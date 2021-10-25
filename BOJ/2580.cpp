#include <iostream>

using namespace std;

int sudoku[9][9];
bool row[10][10];
bool col[10][10];
bool square[10][10];

int getSquare(int x, int y) { return (y / 3) * 3 + (x / 3); }

bool solve(int pos) {
  if (pos == 81) {
    return true;
  }

  int y = pos / 9;
  int x = pos % 9;

  if (sudoku[y][x] != 0) {
    return solve(pos + 1);
  } else {
    for (int i = 1; i <= 9; i++) {
      if (row[y][i] == 0 && col[x][i] == 0 && square[getSquare(x, y)][i] == 0) {
        row[y][i] = col[x][i] = square[getSquare(x, y)][i] = true;
        sudoku[y][x] = i;

        if (solve(pos + 1)) {
          return true;
        }

        sudoku[y][x] = 0;
        row[y][i] = col[x][i] = square[getSquare(x, y)][i] = false;
      }
    }
  }

  return false;
}

int main() {
  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      cin >> sudoku[y][x];

      if (sudoku[y][x] != 0) {
        row[y][sudoku[y][x]] = true;
        col[x][sudoku[y][x]] = true;
        square[getSquare(x, y)][sudoku[y][x]] = true;
      }
    }
  }

  solve(0);

  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      cout << sudoku[y][x] << ' ';
    }
    cout << '\n';
  }
}