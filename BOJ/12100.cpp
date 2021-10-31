#include <iostream>
#include <vector>

using namespace std;

int N;

vector<int> getMoves(int k) {
  vector<int> result;

  for (int i = 0; i < 5; i++) {
    result.push_back(k & 3);
    k >>= 2;
  }

  return result;
}

void moveUp(vector<vector<pair<int, int>>> &board) {
  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N; y++) {
      int ny = y;
      while (true) {
        if (ny == 0) break;

        if (board[ny - 1][x].second == 1 || board[ny][x].second == 1) break;

        if (board[ny - 1][x].first == 0) {
          swap(board[ny][x], board[ny - 1][x]);
        } else if (board[ny - 1][x].first == board[ny][x].first) {
          board[ny - 1][x].first += board[ny][x].first;
          board[ny - 1][x].second = 1;

          board[ny][x].first = 0;
          board[ny][x].second = 0;
        } else {
          break;
        }

        ny--;
      }
    }
  }
}

void moveDown(vector<vector<pair<int, int>>> &board) {
  for (int x = 0; x < N; x++) {
    for (int y = N - 1; y >= 0; y--) {
      int ny = y;
      while (true) {
        if (ny == N - 1) break;

        if (board[ny + 1][x].second == 1 || board[ny][x].second == 1) break;

        if (board[ny + 1][x].first == 0) {
          swap(board[ny][x], board[ny + 1][x]);
        } else if (board[ny + 1][x].first == board[ny][x].first) {
          board[ny + 1][x].first += board[ny][x].first;
          board[ny + 1][x].second = 1;

          board[ny][x].first = 0;
          board[ny][x].second = 0;
        } else {
          break;
        }

        ny++;
      }
    }
  }
}

void moveLeft(vector<vector<pair<int, int>>> &board) {
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      int nx = x;
      while (true) {
        if (nx == 0) break;

        if (board[y][nx - 1].second == 1 || board[y][nx].second == 1) break;

        if (board[y][nx - 1].first == 0) {
          swap(board[y][nx], board[y][nx - 1]);
        } else if (board[y][nx - 1].first == board[y][nx].first) {
          board[y][nx - 1].first += board[y][nx].first;
          board[y][nx - 1].second = 1;

          board[y][nx].first = 0;
          board[y][nx].second = 0;
        } else {
          break;
        }

        nx--;
      }
    }
  }
}

void moveRight(vector<vector<pair<int, int>>> &board) {
  for (int y = 0; y < N; y++) {
    for (int x = N - 1; x >= 0; x--) {
      int nx = x;
      while (true) {
        if (nx == N - 1) break;

        if (board[y][nx + 1].second == 1 || board[y][nx].second == 1) break;

        if (board[y][nx + 1].first == 0) {
          swap(board[y][nx], board[y][nx + 1]);
        } else if (board[y][nx + 1].first == board[y][nx].first) {
          board[y][nx + 1].first += board[y][nx].first;
          board[y][nx + 1].second = 1;

          board[y][nx].first = 0;
          board[y][nx].second = 0;
        } else {
          break;
        }

        nx++;
      }
    }
  }
}

int simulate(vector<vector<pair<int, int>>> board, vector<int> moves) {
  for (int m : moves) {
    switch (m) {
      case 0:
        moveUp(board);
        break;
      case 1:
        moveRight(board);
        break;
      case 2:
        moveDown(board);
        break;
      case 3:
        moveLeft(board);
        break;
    }

    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        board[y][x].second = 0;
      }
    }
  }

  int result = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      result = max(result, board[y][x].first);
    }
  }

  return result;
}

int main() {
  cin >> N;

  vector<vector<pair<int, int>>> board;
  for (int y = 0; y < N; y++) {
    vector<pair<int, int>> row;
    for (int x = 0; x < N; x++) {
      int n;

      cin >> n;

      row.push_back({n, 0});
    }

    board.push_back(row);
  }

  int result = 0;
  for (int i = 0; i < (1 << 10); i++) {
    vector<int> moves = getMoves(i);

    int res = simulate(board, moves);

    result = max(result, res);
  }

  cout << result;
}