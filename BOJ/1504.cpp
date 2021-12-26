#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;

struct Edge {
  int to, cost;
};

struct Vertex {
  int index, dist;

  bool operator>(const Vertex &other) const { return dist > other.dist; }
};

int N, E;
vector<Edge> edges[801];

vector<int> dijkstra(int start) {
  vector<int> dist(N + 1, INF);
  vector<bool> visited(N + 1, false);

  priority_queue<Vertex, vector<Vertex>, greater<>> pq;

  pq.push({start, 0});
  dist[start] = 0;

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    if (visited[cur.index]) continue;

    visited[cur.index] = true;

    for (auto next : edges[cur.index]) {
      int cost = cur.dist + next.cost;
      if (dist[next.to] == INF || cost < dist[next.to]) {
        dist[next.to] = cost;
        pq.push({next.to, cost});
      }
    }
  }

  return dist;
}

int main() {
  cin >> N >> E;

  int a, b, c;
  for (int i = 0; i < E; i++) {
    cin >> a >> b >> c;

    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }

  int v1, v2;

  cin >> v1 >> v2;

  auto dist1 = dijkstra(1);
  auto distv1 = dijkstra(v1);
  auto distv2 = dijkstra(v2);

  if (dist1[v1] == INF || distv1[v2] == INF || distv2[v1] == INF) {
    cout << -1;
  } else {
    cout << min(dist1[v1] + distv1[v2] + distv2[N],
                dist1[v2] + distv2[v1] + distv1[N]);
  }
}