#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
int map[9][9];
int map2[9][9];

pair<int, int> getPos(int n) { return {n % M, n / M}; }

int bfs() {
  queue<pair<int, int>> q;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      map2[y][x] = map[y][x];
      if (map[y][x] == 2) {
        q.push({x, y});
      }
    }
  }

  int xc, yc, xn, yn;
  while (!q.empty()) {
    tie(xc, yc) = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      xn = xc + dx[i];
      yn = yc + dy[i];

      if (xn < 0 || yn < 0 || xn > M - 1 || yn > N - 1) continue;

      if (map2[yn][xn] != 0) continue;

      q.push({xn, yn});
      map2[yn][xn] = 2;
    }
  }

  int result = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (map2[y][x] == 0) {
        result++;
      }
    }
  }

  return result;
}

int main() {
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> map[y][x];
    }
  }

  int result = -987654321;
  for (int i = 0; i < N * M; i++) {
    for (int j = 0; j < N * M; j++) {
      for (int k = 0; k < N * M; k++) {
        if (i == j || i == k || j == k) continue;

        int xi, yi, xj, yj, xk, yk;
        tie(xi, yi) = getPos(i);
        tie(xj, yj) = getPos(j);
        tie(xk, yk) = getPos(k);

        if (map[yi][xi] == 1 || map[yi][xi] == 2 || map[yj][xj] == 1 ||
            map[yj][xj] == 2 || map[yk][xk] == 1 || map[yk][xk] == 2)
          continue;

        map[yi][xi] = map[yj][xj] = map[yk][xk] = 1;

        memset(map2, 0, sizeof(map2));
        result = max(result, bfs());

        map[yi][xi] = map[yj][xj] = map[yk][xk] = 0;
      }
    }
  }

  cout << result;
}