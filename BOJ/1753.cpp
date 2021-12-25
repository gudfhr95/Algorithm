#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int inf = 987654321;

struct Edge {
  int to, cost;
};

struct Vertex {
  int index, dist;

  bool operator>(const Vertex &other) const { return dist > other.dist; }
};

vector<Edge> adj[20001];
int dist[20001];
bool visited[20001];

int main() {
  int V, E, start;

  cin >> V >> E >> start;

  int u, v, w;
  for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;

    adj[u].push_back({v, w});
  }

  for (int i = 1; i <= V; i++) {
    dist[i] = inf;
  }

  priority_queue<Vertex, vector<Vertex>, greater<>> pq;

  dist[start] = 0;
  pq.push({start, 0});

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    if (visited[cur.index]) continue;

    visited[cur.index] = true;
    for (auto next : adj[cur.index]) {
      int cost = cur.dist + next.cost;

      if (cost < dist[next.to]) {
        dist[next.to] = cost;
        pq.push({next.to, cost});
      }
    }
  }

  for (int i = 1; i <= V; i++) {
    if (dist[i] == inf) {
      cout << "INF\n";
    } else {
      cout << dist[i] << '\n';
    }
  }
}