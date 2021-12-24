#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
vector<int> adj[32001];
int indegree[32001];

void bfs() {
  priority_queue<int, vector<int>, greater<>> q;
  for (int i = 1; i <= N; i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int cur = q.top();
    q.pop();

    cout << cur << ' ';

    for (int next : adj[cur]) {
      indegree[next] -= 1;

      if (indegree[next] == 0) {
        q.push(next);
      }
    }
  }
}

int main() {
  cin >> N >> M;

  int A, B;
  for (int i = 0; i < M; i++) {
    cin >> A >> B;

    adj[A].push_back(B);
    indegree[B] += 1;
  }

  bfs();
}