#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
char board[16][16];
bool checked[16][16];
int result = 0;

bool check(int x, int y, int size) {
  int xn = x;
  int yn = y;

  for (int i = 0; i <= size; i++) {
    for (int k = 0; k < 4; k++) {
      xn = x + (dx[k] * i);
      yn = y + (dy[k] * i);

      if (xn < 0 || yn < 0 || xn > M - 1 || yn > N - 1) {
        return false;
      }

      if (board[yn][xn] == '.') return false;

      if (i != 0 && checked[yn][xn]) return false;

      checked[yn][xn] = true;
    }
  }

  return true;
}

void cross(int xi, int yi, int xj, int yj) {
  int maxSize = max(N, M);

  for (int i = 0; i <= maxSize; i++) {
    for (int j = 0; j <= maxSize; j++) {
      memset(checked, 0, sizeof(checked));
      if (check(xi, yi, i) && check(xj, yj, j)) {
        int iSize = 1 + (4 * i);
        int jSize = 1 + (4 * j);
        result = max(result, iSize * jSize);
      }
    }
  }
}

int main() {
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    cin >> board[y];
  }

  for (int i = 0; i < N * M; i++) {
    for (int j = 0; j < N * M; j++) {
      int xi = i % M;
      int yi = i / M;

      int xj = j % M;
      int yj = j / M;

      if (board[yi][xi] == '#' && board[yj][xj] == '#') {
        cross(xi, yi, xj, yj);
      }
    }
  }

  cout << result;
}
