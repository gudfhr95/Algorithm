#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int T, V, E;
vector<int> adj[20001];
int group[20001];

void dfs(int start, int g) {
  group[start] = g;

  for (int i = 0; i < adj[start].size(); i++) {
    if (group[adj[start][i]] == 0) {
      dfs(adj[start][i], 3 - g);
    }
  }
}

int main() {
  cin >> T;

  while (T--) {
    cin >> V >> E;

    for (int i = 1; i <= V; i++) {
      adj[i].clear();
    }

    memset(group, 0, sizeof(group));

    for (int i = 0; i < E; i++) {
      int u, v;

      cin >> u >> v;

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (int i = 1; i <= V; i++) {
      if (group[i] == 0) {
        dfs(i, 1);
      }
    }

    bool result = true;
    for (int i = 1; i <= V; i++) {
      for (int j = 0; j < adj[i].size(); j++) {
        if (group[i] == group[adj[i][j]]) result = false;
      }
    }

    if (result) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}