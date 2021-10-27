#include <cstring>
#include <iostream>

using namespace std;

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int N;
int board[9][9];
bool domino[10][10];
bool row[10][10];
bool col[10][10];
bool square[10][10];

int getSquare(int x, int y) { return ((y / 3) * 3) + (x / 3); }

bool canSet(int x, int y, int num) {
  return !row[y][num] && !col[x][num] && !square[getSquare(x, y)][num];
}

void setNumber(int x, int y, int num, bool value) {
  row[y][num] = value;
  col[x][num] = value;
  square[getSquare(x, y)][num] = value;
}

bool isInRange(int x, int y) { return 0 <= x && x < 9 && 0 <= y && y < 9; }

bool solve(int pos) {
  if (pos == 81) return true;

  int y_pos = pos / 9;
  int x_pos = pos % 9;

  if (board[y_pos][x_pos] != 0) {
    return solve(pos + 1);
  } else {
    for (int i = 0; i < 2; i++) {
      int ny_pos = y_pos + dy[i];
      int nx_pos = x_pos + dx[i];

      if (!isInRange(nx_pos, ny_pos)) continue;

      if (board[ny_pos][nx_pos] != 0) continue;

      for (int y = 1; y <= 9; y++) {
        for (int x = 1; x <= 9; x++) {
          if (x == y) continue;

          if (domino[y][x]) continue;

          if (canSet(x_pos, y_pos, y) && canSet(nx_pos, ny_pos, x)) {
            setNumber(x_pos, y_pos, y, true);
            setNumber(nx_pos, ny_pos, x, true);
            domino[y][x] = domino[x][y] = true;
            board[y_pos][x_pos] = y;
            board[ny_pos][nx_pos] = x;

            if (solve(pos + 1)) {
              return true;
            }

            setNumber(x_pos, y_pos, y, false);
            setNumber(nx_pos, ny_pos, x, false);
            domino[y][x] = domino[x][y] = false;
            board[y_pos][x_pos] = 0;
            board[ny_pos][nx_pos] = 0;
          }
        }
      }
    }
  }

  return false;
}

int main() {
  for (int i = 1;; i++) {
    cin >> N;

    if (N == 0) break;

    memset(board, 0, sizeof(board));
    memset(domino, false, sizeof(domino));
    memset(row, false, sizeof(row));
    memset(col, false, sizeof(col));
    memset(square, false, sizeof(square));

    int y, x;
    for (int i = 0; i < N; i++) {
      int U, V;
      string LU, LV;

      cin >> U >> LU >> V >> LV;

      y = LU[0] - 'A';
      x = LU[1] - '0' - 1;

      board[y][x] = U;
      row[y][U] = true;
      col[x][U] = true;
      square[getSquare(x, y)][U] = true;

      y = LV[0] - 'A';
      x = LV[1] - '0' - 1;

      board[y][x] = V;
      row[y][V] = true;
      col[x][V] = true;
      square[getSquare(x, y)][V] = true;

      domino[U][V] = true;
      domino[V][U] = true;
    }

    for (int i = 1; i <= 9; i++) {
      string LW;

      cin >> LW;

      y = LW[0] - 'A';
      x = LW[1] - '0' - 1;

      board[y][x] = i;
      row[y][i] = true;
      col[x][i] = true;
      square[getSquare(x, y)][i] = true;
    }

    solve(0);

    cout << "Puzzle " << i << '\n';
    for (int y = 0; y < 9; y++) {
      for (int x = 0; x < 9; x++) {
        cout << board[y][x];
      }
      cout << '\n';
    }
  }
}