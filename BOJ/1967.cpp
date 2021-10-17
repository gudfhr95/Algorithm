#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int to;
  int cost;

  Edge(int to, int cost) : to(to), cost(cost) {}
};

vector<Edge> tree[10001];
bool visited[10001];
int dist[10001];

void bfs(int start) {
  memset(dist, 0, sizeof(dist));
  memset(visited, false, sizeof(visited));

  queue<int> q;

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int current = q.front();

    q.pop();

    for (int i = 0; i < tree[current].size(); i++) {
      Edge &e = tree[current][i];

      if (!visited[e.to]) {
        q.push(e.to);
        visited[e.to] = true;
        dist[e.to] = dist[current] + e.cost;
      }
    }
  }
}

int main() {
  int n;

  scanf("%d", &n);

  for (int i = 0; i < n - 1; i++) {
    int u, v, w;

    scanf("%d %d %d", &u, &v, &w);

    tree[u].push_back(Edge(v, w));
    tree[v].push_back(Edge(u, w));
  }

  bfs(1);

  int start = 1;
  for (int i = 2; i <= n; i++) {
    if (dist[i] > dist[start]) {
      start = i;
    }
  }

  bfs(start);

  int ans = dist[1];
  for (int i = 2; i <= n; i++) {
    ans = max(ans, dist[i]);
  }

  printf("%d\n", ans);
}