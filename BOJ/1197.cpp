#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int from, to, cost;

  bool operator<(const Edge &other) const { return cost < other.cost; }
};

int p[10001];

int Find(int x) {
  if (x == p[x]) {
    return x;
  } else {
    return p[x] = Find(p[x]);
  }
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);
  p[x] = y;
}

int main() {
  int V, E;

  cin >> V >> E;

  for (int i = 1; i <= V; i++) {
    p[i] = i;
  }

  vector<Edge> edges(E);

  for (int i = 0; i < E; i++) {
    cin >> edges[i].from >> edges[i].to >> edges[i].cost;
  }

  sort(edges.begin(), edges.end());

  int result = 0;
  for (int i = 0; i < E; i++) {
    Edge e = edges[i];

    int pFrom = Find(e.from);
    int pTo = Find(e.to);
    if (pFrom != pTo) {
      Union(e.from, e.to);
      result += e.cost;
    }
  }

  cout << result;
}