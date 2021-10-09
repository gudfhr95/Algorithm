#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> adj[3001];
int check[3001];
int dist[3001];
queue<int> q;

int dfs(int start, int p) {
  if (check[start] == 1) return start;

  check[start] = 1;
  for (int a : adj[start]) {
    if (a == p) continue;

    int result = dfs(a, start);

    if (result == -2) return -2;

    if (result >= 0) {
      check[start] = 2;
      if (start == result)
        return -2;
      else
        return result;
    }
  }

  return -1;
}

void bfs() {
  while (!q.empty()) {
    int x = q.front();

    q.pop();

    for (int x2 : adj[x]) {
      if (dist[x2] == -1) {
        q.push(x2);
        dist[x2] = dist[x] + 1;
      }
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    int x, y;

    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(1, 0);

  for (int i = 1; i <= N; i++) {
    if (check[i] == 2) {
      dist[i] = 0;
      q.push(i);
    } else {
      dist[i] = -1;
    }
  }

  bfs();

  for (int i = 1; i <= N; i++) {
    cout << dist[i] << ' ';
  }
}