#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int adj[101];
int dist[101];

void bfs(int start) {
  queue<int> q;

  q.push(start);
  dist[start] = 0;

  while (!q.empty()) {
    int current = q.front();

    q.pop();

    for (int i = 1; i <= 6; i++) {
      int next = current + i;

      if (next > 100) continue;

      next = adj[next];

      if (dist[next] != -1) continue;

      q.push(next);
      dist[next] = dist[current] + 1;
    }
  }
}

int main() {
  int N, M;

  cin >> N >> M;

  for (int i = 1; i <= 100; i++) {
    adj[i] = i;
    dist[i] = -1;
  }

  for (int i = 0; i < N; i++) {
    int x, y;

    cin >> x >> y;

    adj[x] = y;
  }

  for (int i = 0; i < M; i++) {
    int u, v;

    cin >> u >> v;

    adj[u] = v;
  }

  bfs(1);

  cout << dist[100];
}