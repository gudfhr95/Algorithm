#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int N, M;

vector<int> getMoves(int k) {
  vector<int> result;
  for (int i = 0; i < 10; i++) {
    result.push_back(k & 3);
    k >>= 2;
  }

  return result;
}

bool valid(vector<int> &moves) {
  for (int i = 0; i < 9; i++) {
    if (moves[i] == 0 && moves[i + 1] == 1) return false;
    if (moves[i] == 1 && moves[i + 1] == 0) return false;
    if (moves[i] == 2 && moves[i + 1] == 3) return false;
    if (moves[i] == 3 && moves[i + 1] == 2) return false;
    if (moves[i] == moves[i + 1]) return false;
  }

  return true;
}

pair<bool, bool> move(vector<string> &board, int m, int &x, int &y) {
  if (board[y][x] == '.') return {false, false};

  bool moved = false;
  while (true) {
    int nx = x + dx[m];
    int ny = y + dy[m];

    if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
      return {moved, false};
    }

    if (board[ny][nx] == '#') {
      return {moved, false};
    } else if (board[ny][nx] == 'R' || board[ny][nx] == 'B') {
      return {moved, false};
    } else if (board[ny][nx] == '.') {
      swap(board[ny][nx], board[y][x]);
      x = nx;
      y = ny;
      moved = true;
    } else if (board[ny][nx] == 'O') {
      board[y][x] = '.';
      moved = true;
      return make_pair(moved, true);
    }
  }

  return {false, false};
}

int simulate(vector<string> board, vector<int> &moves) {
  int hx, hy, rx, ry, bx, by;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (board[y][x] == 'O') {
        hx = x;
        hy = y;
      } else if (board[y][x] == 'R') {
        rx = x;
        ry = y;
      } else if (board[y][x] == 'B') {
        bx = x;
        by = y;
      }
    }
  }

  int cnt = 0;
  for (int m : moves) {
    cnt++;

    bool r_in = false;
    bool b_in = false;

    while (true) {
      pair<bool, bool> rpos = move(board, m, rx, ry);
      pair<bool, bool> bpos = move(board, m, bx, by);

      if (rpos.first == false && bpos.first == false) {
        break;
      }

      if (rpos.second) r_in = true;
      if (bpos.second) b_in = true;
    }

    if (b_in) return -1;
    if (r_in) return cnt;
  }

  return -1;
}

int main() {
  cin >> N >> M;

  vector<string> board;
  for (int y = 0; y < N; y++) {
    string s;

    cin >> s;

    board.push_back(s);
  }

  int result = -1;
  for (int i = 0; i < (1 << (10 * 2)); i++) {
    vector<int> moves = getMoves(i);

    if (!valid(moves)) continue;

    int res = simulate(board, moves);

    if (res == -1) continue;

    if (result == -1 || result > res) {
      result = res;
    }
  }

  cout << result;
}