#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int to, cost;
};

vector<Edge> edges[40001];
int parent[40001];
int depth[40001];
bool visited[40001];
int dist[40001];

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  while (depth[u] != depth[v]) {
    u = parent[u];
  }

  while (u != v) {
    u = parent[u];
    v = parent[v];
  }

  return u;
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int a, b, c;

    cin >> a >> b >> c;

    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }

  parent[1] = 0;
  depth[1] = 0;
  visited[1] = true;

  queue<int> q;

  q.push(1);

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto &next : edges[cur]) {
      if (!visited[next.to]) {
        depth[next.to] = depth[cur] + 1;
        dist[next.to] = dist[cur] + next.cost;
        visited[next.to] = true;
        parent[next.to] = cur;
        q.push(next.to);
      }
    }
  }

  int m;

  cin >> m;

  for (int i = 0; i < m; i++) {
    int u, v;

    cin >> u >> v;

    cout << dist[u] + dist[v] - 2 * dist[lca(u, v)] << '\n';
  }
}