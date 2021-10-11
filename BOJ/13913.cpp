#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int dx[2] = {-1, 1};

int N, K;
int dist[100001];
int path[100001];

void print(int n, int k) {
  if (n != k) {
    print(n, path[k]);
  }
  cout << k << ' ';
}

void bfs(int start) {
  queue<int> q;

  q.push(start);
  dist[start] = 0;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    for (int i = 0; i < 2; i++) {
      int next = current + dx[i];

      if (next < 0 || next > 100000) continue;

      if (dist[next] != -1) continue;

      q.push(next);
      dist[next] = dist[current] + 1;
      path[next] = current;
    }

    int next = current * 2;

    if (next < 0 || next > 100000) continue;

    if (dist[next] != -1) continue;

    q.push(next);
    dist[next] = dist[current] + 1;
    path[next] = current;
  }
}

int main() {
  cin >> N >> K;

  memset(dist, -1, sizeof(dist));

  bfs(N);

  cout << dist[K] << '\n';

  print(N, K);

  return 0;
}