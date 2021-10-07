#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[8] = {0, -1, 0, 1};

int N, M;
int map[100][100];
int path[100][100];

void bfs(int x, int y) {
  queue<pair<int, int>> q;

  q.push({x, y});
  path[y][x] = 1;

  while (!q.empty()) {
    int x1 = q.front().first;
    int y1 = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int x2 = x1 + dx[i];
      int y2 = y1 + dy[i];

      if (x2 < 0 || y2 < 0 || x2 > M - 1 || y2 > N - 1) continue;

      if (path[y2][x2] != 0 || map[y2][x2] == 0) continue;

      q.push({x2, y2});
      path[y2][x2] = path[y1][x1] + 1;
    }
  }
}

int main() {
  scanf("%d %d", &N, &M);

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      scanf("%1d", &map[y][x]);
    }
  }

  bfs(0, 0);

  cout << path[N - 1][M - 1];
}