#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const long long INF = 100000000000LL;

struct Edge {
  int to;
  long long cost;
};

struct Vertex {
  int index, k;
  long long dist;

  bool operator>(const Vertex &v) const { return dist > v.dist; }
};

int N, M, K;
vector<Edge> edges[10001];
long long dist[10001][21];
bool visited[10001][21];

int main() {
  cin >> N >> M >> K;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= K; j++) {
      dist[i][j] = INF;
    }
  }

  int a, b;
  long long c;
  for (int i = 0; i < M; i++) {
    cin >> a >> b >> c;

    edges[a].push_back({b, c});
    edges[b].push_back({a, c});
  }

  priority_queue<Vertex, vector<Vertex>, greater<>> pq;

  dist[1][0] = 0;
  pq.push({1, 0, 0});

  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    if (visited[cur.index][cur.k]) continue;

    visited[cur.index][cur.k] = true;

    for (auto next : edges[cur.index]) {
      long long cost = cur.dist + next.cost;
      if (dist[next.to][cur.k] == INF || dist[next.to][cur.k] > cost) {
        dist[next.to][cur.k] = cost;
        pq.push({next.to, cur.k, cost});
      }

      if (cur.k + 1 <= K && (dist[next.to][cur.k + 1] == INF ||
                             dist[next.to][cur.k + 1] > cur.dist)) {
        dist[next.to][cur.k + 1] = cur.dist;
        pq.push({next.to, cur.k + 1, cur.dist});
      }
    }
  }

  long long result = INF;
  for (int k = 0; k <= K; k++) {
    result = min(result, dist[N][k]);
  }

  cout << result;
}