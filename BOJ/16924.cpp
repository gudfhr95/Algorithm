#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
char board[101][101];
bool checked[101][101];
vector<tuple<int, int, int>> results;

bool check(int x, int y, int dist) {
  for (int k = 0; k < 4; k++) {
    int xn = x + (dx[k] * dist);
    int yn = y + (dy[k] * dist);

    if (xn < 0 || yn < 0 || xn > M - 1 || yn > N - 1) {
      return false;
    }

    if (board[yn][xn] != '*') {
      return false;
    }
  }

  return true;
}

void cross(int x, int y) {
  int dist = 1;
  while (true) {
    if (check(x, y, dist)) {
      checked[y][x] = false;
      for (int k = 0; k < 4; k++) {
        int xn = x + (dx[k] * dist);
        int yn = y + (dy[k] * dist);

        checked[yn][xn] = false;
      }
      dist++;
    } else {
      if (dist != 1) {
        results.push_back({x, y, dist - 1});
      }
      return;
    }
  }
}

int main() {
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    cin >> board[y];

    for (int x = 0; x < M; x++) {
      if (board[y][x] == '*') {
        checked[y][x] = true;
      }
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (board[y][x] == '*') {
        cross(x, y);
      }
    }
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (checked[y][x]) {
        cout << -1;
        return 0;
      }
    }
  }

  cout << results.size() << '\n';

  int x, y, d;
  for (const auto &result : results) {
    tie(x, y, d) = result;
    cout << y + 1 << ' ' << x + 1 << ' ' << d << '\n';
  }
}