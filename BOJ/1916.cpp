#include <iostream>
#include <vector>

using namespace std;

int inf = 987654321;

struct Edge {
  int to, cost;
};

int N, M;
vector<Edge> edges[1001];
int dist[1001];
bool visited[1001];

int main() {
  cin >> N >> M;

  int A, B, C;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;

    edges[A].push_back({B, C});
  }

  for (int i = 1; i <= N; i++) {
    dist[i] = inf;
  }

  int start, end;

  cin >> start >> end;

  dist[start] = 0;

  int cur = start;
  for (int i = 0; i < N - 1; i++) {
    visited[cur] = true;

    for (auto &next : edges[cur]) {
      int cost = dist[cur] + next.cost;

      dist[next.to] = min(dist[next.to], cost);
    }

    int nextIndex = 0;
    int nextDist = 987654321;
    for (int j = 1; j <= N; j++) {
      if (visited[j]) continue;
      if (dist[j] < nextDist) {
        nextIndex = j;
        nextDist = dist[j];
      }
    }

    cur = nextIndex;
  }

  cout << dist[end];
}