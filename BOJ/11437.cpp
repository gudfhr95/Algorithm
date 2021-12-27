#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> a[50001];
int parent[50001];
int depth[50001];
bool check[50001];

int lca(int u, int v) {
  if (depth[u] < depth[v]) {
    swap(u, v);
  }

  while (depth[u] != depth[v]) {
    u = parent[u];
  }

  while (u != v) {
    u = parent[u];
    v = parent[v];
  }

  return u;
}

int main() {
  int N;

  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int u, v;

    cin >> u >> v;

    a[u].push_back(v);
    a[v].push_back(u);
  }

  depth[1] = 0;
  check[1] = true;

  queue<int> q;

  q.push(1);
  parent[1] = 0;

  while (!q.empty()) {
    int x = q.front();
    q.pop();

    for (int y : a[x]) {
      if (!check[y]) {
        depth[y] = depth[x] + 1;
        check[y] = true;
        parent[y] = x;
        q.push(y);
      }
    }
  }

  int m;

  cin >> m;

  for (int i = 0; i < m; i++) {
    int u, v;

    cin >> u >> v;

    cout << lca(u, v) << '\n';
  }
}