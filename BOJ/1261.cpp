#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int M, N;
int maze[101][101];
int dist[101][101];

void bfs(int x, int y) {
  queue<pair<int, int>> q;

  q.push({x, y});
  dist[y][x] = 0;

  while (!q.empty()) {
    int x_current = q.front().first;
    int y_current = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int x_next = x_current + dx[i];
      int y_next = y_current + dy[i];

      if (x_next < 1 || y_next < 1 || x_next > M || y_next > N) continue;

      int next_dist = dist[y_current][x_current];

      if (maze[y_next][x_next] == 1) {
        next_dist++;
      }

      if (dist[y_next][x_next] == -1 || dist[y_next][x_next] > next_dist) {
        q.push({x_next, y_next});
        dist[y_next][x_next] = next_dist;
      }
    }
  }
}

int main() {
  scanf("%d %d", &M, &N);

  for (int y = 1; y <= N; y++) {
    for (int x = 1; x <= M; x++) {
      scanf("%1d", &maze[y][x]);
    }
  }

  memset(dist, -1, sizeof(dist));

  bfs(1, 1);

  cout << dist[N][M];
}