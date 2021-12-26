#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int to, cost;
};

struct Vertex {
  int index, dist;

  bool operator>(const Vertex &v) const { return dist > v.dist; }
};

int n, m, k;
vector<Edge> edges[1001];
priority_queue<int> dist[1001];

int main() {
  cin >> n >> m >> k;

  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;

    edges[a].push_back({b, c});
  }

  priority_queue<Vertex, vector<Vertex>, greater<>> pq;

  pq.push({1, 0});
  dist[1].push(0);

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    for (auto next : edges[cur.index]) {
      int cost = cur.dist + next.cost;
      if (dist[next.to].size() < k || dist[next.to].top() > cost) {
        if (dist[next.to].size() == k) {
          dist[next.to].pop();
        }

        dist[next.to].push(cost);
        pq.push({next.to, cost});
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dist[i].size() < k) {
      cout << -1 << '\n';
    } else {
      cout << dist[i].top() << '\n';
    }
  }
}