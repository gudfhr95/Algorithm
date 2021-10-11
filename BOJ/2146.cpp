#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N;
int board[100][100];
int map[100][100];
int dist[100][100];

void color(int x, int y, int c) {
  queue<pair<int, int>> q;

  q.push({x, y});
  map[y][x] = c;

  while (!q.empty()) {
    int x_cur = q.front().first;
    int y_cur = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int x_next = x_cur + dx[i];
      int y_next = y_cur + dy[i];

      if (x_next < 0 || y_next < 0 || x_next > N - 1 || y_next > N - 1)
        continue;

      if (board[y_next][x_next] == 0 || map[y_next][x_next] != 0) continue;

      q.push({x_next, y_next});
      map[y_next][x_next] = c;
    }
  }
}

void expand(queue<pair<int, int>> q) {
  while (!q.empty()) {
    int x_cur = q.front().first;
    int y_cur = q.front().second;

    q.pop();

    for (int i = 0; i < 4; i++) {
      int x_next = x_cur + dx[i];
      int y_next = y_cur + dy[i];

      if (x_next < 0 || y_next < 0 || x_next > N - 1 || y_next > N - 1)
        continue;

      if (map[y_next][x_next] != 0) continue;

      q.push({x_next, y_next});
      map[y_next][x_next] = map[y_cur][x_cur];
      dist[y_next][x_next] = dist[y_cur][x_cur] + 1;
    }
  }
}

int main() {
  cin >> N;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> board[y][x];
    }
  }

  int c = 1;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (board[y][x] == 1 && map[y][x] == 0) {
        color(x, y, c++);
      }
    }
  }

  queue<pair<int, int>> q;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (map[y][x] != 0) {
        q.push({x, y});
        dist[y][x] = 0;
      }
    }
  }

  expand(q);

  int result = 987654321;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N - 1; x++) {
      if (map[y][x] != map[y][x + 1]) {
        result = min(result, dist[y][x] + dist[y][x + 1]);
      }
    }
  }

  for (int x = 0; x < N; x++) {
    for (int y = 0; y < N - 1; y++) {
      if (map[y][x] != map[y + 1][x]) {
        result = min(result, dist[y][x] + dist[y + 1][x]);
      }
    }
  }

  cout << result;
}