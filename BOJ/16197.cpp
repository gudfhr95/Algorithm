#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
char board[21][21];
vector<pair<int, int>> coinPos;

int move(int cnt, int x1, int y1, int x2, int y2) {
  if (cnt == 11) return -1;

  bool f1 = false;
  bool f2 = false;

  if (x1 < 0 || x1 > M - 1 || y1 < 0 || y1 > N - 1) {
    f1 = true;
  }
  if (x2 < 0 || x2 > M - 1 || y2 < 0 || y2 > N - 1) {
    f2 = true;
  }

  if (f1 == true && f2 == true) {
    return -1;
  } else if (f1 == true || f2 == true) {
    return cnt;
  }

  int result = -1;
  for (int i = 0; i < 4; i++) {
    int nx1 = x1 + dx[i];
    int ny1 = y1 + dy[i];
    int nx2 = x2 + dx[i];
    int ny2 = y2 + dy[i];

    if (board[ny1][nx1] == '#') {
      nx1 = x1;
      ny1 = y1;
    }

    if (board[ny2][nx2] == '#') {
      nx2 = x2;
      ny2 = y2;
    }

    int moves = move(cnt + 1, nx1, ny1, nx2, ny2);
    if (result == -1 && moves != -1) {
      result = moves;
    } else if (result != -1 && moves != -1) {
      result = min(result, moves);
    }
  }

  return result;
}

int main() {
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    cin >> board[y];
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (board[y][x] == 'o') {
        coinPos.push_back({x, y});
      }
    }
  }

  cout << move(0, coinPos[0].first, coinPos[0].second, coinPos[1].first,
               coinPos[1].second);
}