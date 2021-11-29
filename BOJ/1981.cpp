#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N;
int map[100][100];
bool visited[100][100];

bool bfs(int mini, int maxi) {
  queue<pair<int, int>> q;

  memset(visited, false, sizeof(visited));

  if (map[0][0] < mini || map[0][0] > maxi) {
    return false;
  }

  q.push({0, 0});
  visited[0][0] = true;

  while (!q.empty()) {
    pair<int, int> current = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      int xn = current.first + dx[k];
      int yn = current.second + dy[k];

      if (xn < 0 || yn < 0 || xn > N - 1 || yn > N - 1) continue;

      if (visited[yn][xn]) continue;

      if (map[yn][xn] > maxi) continue;

      if (map[yn][xn] < mini) continue;

      q.push({xn, yn});
      visited[yn][xn] = true;
    }
  }

  return visited[N - 1][N - 1];
}

bool check(int diff) {
  for (int mini = 0; mini + diff <= 200; mini++) {
    if (bfs(mini, mini + diff)) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> N;

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      cin >> map[y][x];
    }
  }

  int l = 0;
  int r = 200;
  int result = 987654321;

  while (l <= r) {
    int mid = (l + r) / 2;

    if (check(mid)) {
      result = min(result, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }

  cout << result;
}