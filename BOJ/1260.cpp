#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int N;
int graph[1001][1001];
bool visited[1001];

void bfs(int start) {
  queue<int> q;

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    cout << v << ' ';

    for (int i = 1; i <= N; i++) {
      if (!visited[i] && graph[v][i] == 1) {
        q.push(i);
        visited[i] = true;
      }
    }
  }
}

void dfs(int start) {
  visited[start] = true;
  cout << start << ' ';

  for (int i = 1; i <= N; i++) {
    if (!visited[i] && graph[start][i] == 1) {
      dfs(i);
    }
  }
}

int main() {
  int M, V;

  cin >> N >> M >> V;

  for (int i = 0; i < M; i++) {
    int from, to;

    cin >> from >> to;

    graph[from][to] = graph[to][from] = true;
  }

  memset(visited, false, sizeof(visited));
  dfs(V);
  cout << '\n';

  memset(visited, false, sizeof(visited));
  bfs(V);
}