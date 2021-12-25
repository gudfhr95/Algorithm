#include <iostream>
#include <vector>

using namespace std;

int inf = 987654321;

struct Edge {
  int from, to, cost;
};

int N, M, W;
vector<Edge> edges;
long long dist[501];

bool go() {
  bool cycle = false;

  dist[1] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < (2 * M) + W; j++) {
      Edge e = edges[j];

      long long cost = dist[e.from] + e.cost;

      if (cost < dist[e.to]) {
        dist[e.to] = cost;

        if (i == N) {
          cycle = true;
        }
      }
    }
  }

  if (cycle) {
    return true;
  } else {
    return false;
  }
}

int main() {
  int TC;

  cin >> TC;

  while (TC--) {
    cin >> N >> M >> W;

    edges.clear();

    int S, E, T;
    for (int i = 0; i < M; i++) {
      cin >> S >> E >> T;

      edges.push_back({S, E, T});
      edges.push_back({E, S, T});
    }

    for (int i = 0; i < W; i++) {
      cin >> S >> E >> T;

      edges.push_back({S, E, -T});
    }

    for (int i = 1; i <= N; i++) {
      dist[i] = 0;
    }

    if (go()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}