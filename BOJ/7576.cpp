#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int M, N;
int tomato[1000][1000];
int days[1000][1000];
queue<pair<int, int>> q;

void bfs() {
  while (!q.empty()) {
    int x1 = q.front().first;
    int y1 = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int x2 = x1 + dx[i];
      int y2 = y1 + dy[i];

      if (x2 < 0 || y2 < 0 || x2 > M - 1 || y2 > N - 1) continue;

      if (tomato[y2][x2] == -1 || days[y2][x2] != -1) continue;

      q.push({x2, y2});
      days[y2][x2] = days[y1][x1] + 1;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> M >> N;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      cin >> tomato[y][x];

      days[y][x] = tomato[y][x] - 1;

      if (tomato[y][x] == 1) {
        q.push({x, y});
      }
    }
  }

  bfs();

  int result = -987654321;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (days[y][x] == -1) {
        cout << -1;
        return 0;
      }

      result = max(result, days[y][x]);
    }
  }

  cout << result;
}