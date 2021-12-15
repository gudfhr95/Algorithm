#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int R, C;
char farm[501][501];

int main() {
  cin >> R >> C;

  for (int y = 0; y < R; y++) {
    cin >> farm[y];
  }

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      if (farm[y][x] == 'W') {
        for (int k = 0; k < 4; k++) {
          int xn = x + dx[k];
          int yn = y + dy[k];

          if (xn < 0 || yn < 0 || xn > C - 1 || yn > R - 1) continue;

          if (farm[yn][xn] == 'S') {
            cout << 0;

            return 0;
          } else if (farm[yn][xn] == '.') {
            farm[yn][xn] = 'D';
          }
        }
      }
    }
  }

  cout << 1 << '\n';

  for (int y = 0; y < R; y++) {
    for (int x = 0; x < C; x++) {
      cout << farm[y][x];
    }
    cout << '\n';
  }
}