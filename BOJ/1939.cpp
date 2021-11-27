#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, start, finish;
vector<pair<int, int>> adj[10001];
bool visited[10001];

bool bfs(int x) {
  queue<int> q;
  memset(visited, false, sizeof(visited));

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int cur = q.front();
    q.pop();

    for (auto next : adj[cur]) {
      if (next.second < x) continue;

      if (visited[next.first]) continue;

      q.push(next.first);
      visited[next.first] = true;
    }
  }

  return visited[finish];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  int A, B, C;
  int max_weight = 0;
  for (int i = 0; i < M; i++) {
    cin >> A >> B >> C;

    adj[A].push_back({B, C});
    adj[B].push_back({A, C});
  }

  cin >> start >> finish;

  int l = 1;
  int r = 1000000000;
  int result = 0;

  while (l <= r) {
    int mid = l + (r - l) / 2;

    if (bfs(mid)) {
      result = max(result, mid);
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }

  cout << result;
}