#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int to;
  int cost;
  bool operator<(const Edge &other) const { return cost > other.cost; }
};

vector<Edge> adj[1001];
bool visited[1001];

int main() {
  int N, M;

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int from, to, cost;

    cin >> from >> to >> cost;

    adj[from].push_back(Edge({to, cost}));
    adj[to].push_back(Edge({from, cost}));
  }

  priority_queue<Edge> q;
  visited[1] = true;

  for (Edge e : adj[1]) {
    q.push(e);
  }

  int result = 0;
  while (!q.empty()) {
    Edge e = q.top();
    q.pop();

    if (visited[e.to]) continue;

    visited[e.to] = true;
    result += e.cost;
    for (Edge next : adj[e.to]) {
      q.push(next);
    }
  }

  cout << result;
}