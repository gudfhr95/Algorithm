#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int N;
int graph[1001][1001];
bool visited[1001];

int result = 0;
void bfs(int start) {
  queue<int> q;

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (int i = 1; i <= N; i++) {
      if (!visited[i] && graph[v][i] == 1) {
        q.push(i);
        visited[i] = true;
      }
    }
  }

  result++;

  for (int i = 1; i <= N; i++) {
    if (!visited[i]) bfs(i);
  }

  return;
}

int main() {
  int M;

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int from, to;

    cin >> from >> to;

    graph[from][to] = graph[to][from] = true;
  }

  memset(visited, false, sizeof(visited));
  bfs(1);

  cout << result;
}