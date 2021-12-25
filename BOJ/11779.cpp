#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int inf = 987654321;

struct Edge {
  int to, cost;
};

vector<Edge> adj[1001];
int dist[1001];
bool visited[1001];
int from[1001];

int main() {
  int n, m;

  cin >> n >> m;

  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;

    adj[a].push_back({b, c});
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = inf;
  }

  int start, end;

  cin >> start >> end;

  dist[start] = 0;
  from[start] = -1;

  for (int i = 0; i < n - 1; i++) {
    int cur = -1;
    int d = 987654321;
    for (int j = 1; j <= n; j++) {
      if (visited[j] != 0) continue;

      if (dist[j] < d) {
        cur = j;
        d = dist[j];
      }
    }

    visited[cur] = true;

    for (auto next : adj[cur]) {
      int cost = dist[cur] + next.cost;
      if (cost < dist[next.to]) {
        dist[next.to] = cost;
        from[next.to] = cur;
      }
    }
  }

  cout << dist[end] << '\n';

  stack<int> st;
  int x = end;
  while (x != -1) {
    st.push(x);
    x = from[x];
  }

  cout << st.size() << '\n';

  while (!st.empty()) {
    cout << st.top() << ' ';
    st.pop();
  }
}