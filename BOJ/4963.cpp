#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int w, h;
int map[100][100];
bool visited[100][100];

void bfs(int x, int y) {
  queue<pair<int, int>> q;

  q.push({x, y});
  visited[y][x] = true;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();

    for (int i = 0; i < 8; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (xx < 0 || yy < 0 || xx > w - 1 || yy > h - 1) continue;

      if (map[yy][xx] == 0 || visited[yy][xx]) continue;

      q.push({xx, yy});
      visited[yy][xx] = true;
    }
  }
}

int main() {
  while (true) {
    cin >> w >> h;

    if (w == 0 && h == 0) break;

    memset(map, 0, sizeof(map));
    memset(visited, false, sizeof(visited));

    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        cin >> map[y][x];
      }
    }

    int result = 0;
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        if (!visited[y][x] && map[y][x] == 1) {
          bfs(x, y);
          result++;
        }
      }
    }

    cout << result << '\n';
  }
}