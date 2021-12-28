#include <iostream>

using namespace std;

const int m = 30;

int d[15][30][30];
int dx[] = {-1, 0, 1, 1, 0, -1};
int dy[] = {1, 1, 0, -1, -1, 0};

int main() {
  d[0][14][14] = 1;

  for (int k = 1; k <= 14; k++) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < m; j++) {
        for (int l = 0; l < 6; l++) {
          int x = i + dx[l];
          int y = j + dy[l];
          if (0 <= x && x < m && 0 <= y && y < m) {
            d[k][i][j] += d[k - 1][x][y];
          }
        }
      }
    }
  }

  int t;

  cin >> t;

  while (t--) {
    int n;

    cin >> n;

    cout << d[n][14][14] << '\n';
  }

  return 0;
}
