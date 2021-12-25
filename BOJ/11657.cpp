#include <iostream>
#include <vector>

using namespace std;

int inf = 987654321;

struct Edge {
  int from, to, cost;
};

int N, M;
vector<Edge> adj;
long long dist[501];

int main() {
  cin >> N >> M;

  int A, B, C;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;

    adj.push_back({A, B, C});
  }

  for (int i = 1; i <= N; i++) {
    dist[i] = inf;
  }

  dist[1] = 0;
  bool negative = false;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < M; j++) {
      Edge e = adj[j];

      long long cost = dist[e.from] + e.cost;
      if (dist[e.from] != inf && cost < dist[e.to]) {
        dist[e.to] = cost;
        if (i == N) {
          negative = true;
        }
      }
    }
  }

  if (negative) {
    cout << -1 << '\n';
  } else {
    for (int i = 2; i <= N; i++) {
      if (dist[i] == inf) dist[i] = -1;
      cout << dist[i] << '\n';
    }
  }
}