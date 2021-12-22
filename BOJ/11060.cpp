#include <iostream>
#include <queue>

using namespace std;

int N;
int A[1000];
int dist[1000];

void bfs(int start) {
  queue<int> q;

  q.push(start);
  dist[start] = 0;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    for (int i = 1; i <= A[current]; i++) {
      int next = current + i;

      if (next > N - 1) continue;

      if (dist[next] != -1) continue;

      q.push(next);
      dist[next] = dist[current] + 1;
    }
  }
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    dist[i] = -1;
  }

  bfs(0);

  cout << dist[N - 1];
}
