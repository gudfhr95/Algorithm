#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int N, M;
int space[50][50];
int dist[50][50];

int main() {
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> space[y][x];
    }
  }

  memset(dist, -1, sizeof(dist));

  queue<pair<int, int>> q;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (space[y][x] == 1) {
        q.push({x, y});
        dist[y][x] = 0;
      }
    }
  }

  int xc, yc, xn, yn;
  while (!q.empty()) {
    tie(xc, yc) = q.front();
    q.pop();

    for (int k = 0; k < 8; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];

      if (xn < 0 || yn < 0 || xn > M - 1 || yn > N - 1) continue;

      if (dist[yn][xn] != -1) continue;

      q.push({xn, yn});
      dist[yn][xn] = dist[yc][xc] + 1;
    }
  }

  int result = 0;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      result = max(result, dist[y][x]);
    }
  }

  cout << result;
}