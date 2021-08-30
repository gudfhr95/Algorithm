#include <cstring>
#include <iostream>

using namespace std;

int GRID[101][101];

int getMovement(int m, int n) {
  int result = 0;

  for (int x = 1; x <= n; x++) {
    for (int y = m - 1; y > 0; y--) {
      if (GRID[y][x] == 1) {
        int index;
        for (index = y + 1; index <= m; index++) {
          if (GRID[index][x] == 1) break;
          result++;
        }
        swap(GRID[y][x], GRID[index - 1][x]);
      }
    }
  }

  return result;
}

int main() {
  int T, m, n, e;

  cin >> T;

  while (T--) {
    cin >> m >> n;

    memset(GRID, 0, sizeof(GRID));

    for (int y = 1; y <= m; y++) {
      for (int x = 1; x <= n; x++) {
        cin >> GRID[y][x];
      }
    }

    cout << getMovement(m, n) << '\n';
  }
}
