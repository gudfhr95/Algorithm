#include <iostream>
#include <vector>

using namespace std;

bool a[2000][2000];
vector<int> g[2000];
vector<pair<int, int>> edges;

int main() {
  int N, M;

  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int from, to;

    cin >> from >> to;

    edges.push_back({from, to});
    edges.push_back({to, from});

    a[from][to] = a[to][from] = true;

    g[from].push_back(to);
    g[to].push_back(from);
  }

  for (int i = 0; i < 2 * M; i++) {
    for (int j = 0; j < 2 * M; j++) {
      int A = edges[i].first;
      int B = edges[i].second;

      int C = edges[j].first;
      int D = edges[j].second;

      if (A == C || A == D || B == C || B == D) continue;

      if (!a[B][C]) continue;

      for (int E : g[D]) {
        if (A == E || B == E || C == E || D == E) continue;

        cout << 1;
        return 0;
      }
    }
  }

  cout << 0;
  return 0;
}