#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Edge {
  int from, to, cost;

  bool operator>(const Edge &e) const { return cost > e.cost; }
};

int N, M;
int p[100001];
priority_queue<Edge, vector<Edge>, greater<>> pq;

int Find(int x) {
  if (x == p[x]) {
    return x;
  }
  return p[x] = Find(p[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  p[x] = y;
}

int main() {
  cin >> N >> M;

  int A, B, C;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;

    pq.push({A, B, C});
  }

  for (int i = 1; i <= N; i++) {
    p[i] = i;
  }

  vector<Edge> edges;
  while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    if (Find(cur.from) == Find(cur.to)) continue;

    Union(cur.from, cur.to);
    edges.push_back(cur);
  }

  sort(edges.begin(), edges.end(), greater<>());

  int result = 0;
  for (int i = 1; i < edges.size(); i++) {
    result += edges[i].cost;
  }

  cout << result;
}