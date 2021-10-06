#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int N;
int map[30][30];
bool visited[30][30];

int post(int x, int y) {
  int result = 0;

  queue<pair<int, int>> q;

  q.push({x, y});
  visited[y][x] = true;

  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;

    q.pop();
    result++;

    for (int i = 0; i < 4; i++) {
      int xx = x + dx[i];
      int yy = y + dy[i];

      if (xx < 0 || xx > N || yy < 0 || yy > N) continue;

      if (map[yy][xx] != 1) continue;

      if (!visited[yy][xx]) {
        q.push({xx, yy});
        visited[yy][xx] = true;
      }
    }
  }

  return result;
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%1d", &map[i][j]);
    }
  }

  vector<int> results;
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (!visited[y][x] && map[y][x] == 1) {
        results.push_back(post(x, y));
      }
    }
  }

  sort(results.begin(), results.end());

  cout << results.size() << '\n';
  for (const auto &elem : results) {
    cout << elem << '\n';
  }
}