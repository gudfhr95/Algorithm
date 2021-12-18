#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
int map[50][50];
int dist[50][50];

int bfs(vector<pair<int, int>> v) {
  queue<pair<int, int>> q;

  for (const auto p : v) {
    q.push(p);
    dist[p.second][p.first] = 0;
  }

  int xc, yc, xn, yn;
  while (!q.empty()) {
    tie(xc, yc) = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      xn = xc + dx[k];
      yn = yc + dy[k];

      if (xn < 0 || yn < 0 || xn > N - 1 || yn > N - 1) continue;

      if (map[yn][xn] == 1) continue;

      if (dist[yn][xn] != -1) continue;

      q.push({xn, yn});
      dist[yn][xn] = dist[yc][xc] + 1;
    }
  }

  int result = -1;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (map[y][x] == 0 && dist[y][x] == -1) {
        return -1;
      }

      result = max(result, dist[y][x]);
    }
  }

  return result;
}

int main() {
  cin >> N >> M;

  vector<pair<int, int>> viruses;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> map[y][x];

      if (map[y][x] == 2) {
        viruses.push_back({x, y});
      }
    }
  }

  int result = 987654321;
  for (int i = 0; i < (1 << viruses.size()); i++) {
    vector<pair<int, int>> v;

    for (int k = 0; k < viruses.size(); k++) {
      if ((i & (1 << k)) != 0) {
        v.push_back(viruses[k]);
      }
    }

    if (v.size() != M) continue;

    memset(dist, -1, sizeof(dist));
    int res = bfs(v);

    if (res == -1) continue;

    result = min(result, res);
  }

  if (result == 987654321) {
    cout << -1;
  } else {
    cout << result;
  }
}