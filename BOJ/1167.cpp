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

vector<Edge> tree[100001];
bool visited[100001];
int dist[100001];

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
  int V;

  scanf("%d", &V);

  for (int i = 1; i <= V; i++) {
    int x;

    scanf("%d", &x);

    while (true) {
      int y, z;

      scanf("%d", &y);

      if (y == -1) break;

      scanf("%d", &z);

      tree[x].push_back(Edge(y, z));
    }
  }

  bfs(1);

  int start = 1;
  for (int i = 2; i <= V; i++) {
    if (dist[i] > dist[start]) {
      start = i;
    }
  }

  bfs(start);

  int ans = dist[1];
  for (int i = 2; i <= V; i++) {
    ans = max(ans, dist[i]);
  }

  printf("%d\n", ans);
}