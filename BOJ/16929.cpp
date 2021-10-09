#include <cstring>
#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int N, M;
char board[51][51];
bool visited[51][51];
int dist[51][51];

bool dfs(int x, int y, int cnt, char color) {
  if (visited[y][x]) {
    return (cnt - dist[y][x]) >= 4;
  }

  visited[y][x] = true;
  dist[y][x] = cnt;

  for (int i = 0; i < 4; i++) {
    int x_next = x + dx[i];
    int y_next = y + dy[i];

    if (x_next < 0 || y_next < 0 || x_next > M - 1 || y_next > N - 1) continue;

    if (board[y_next][x_next] != color) continue;

    if (dfs(x_next, y_next, cnt + 1, color)) return true;
  }

  return false;
}

int main() {
  cin >> N >> M;

  for (int y = 0; y < N; y++) {
    cin >> board[y];
  }

  for (int y = 0; y < N; y++) {
    for (int x = 0; x < M; x++) {
      if (visited[y][x]) continue;

      memset(dist, 0, sizeof(dist));

      if (dfs(x, y, 1, board[y][x])) {
        cout << "Yes";
        return 0;
      }
    }
  }

  cout << "No";
  return 0;
}