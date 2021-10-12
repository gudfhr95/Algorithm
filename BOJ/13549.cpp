#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int dx[2] = {-1, 1};

int N, K;
int t[100001];

void bfs(int start) {
  queue<int> q;

  q.push(start);
  t[start] = 0;

  while (!q.empty()) {
    int current = q.front();

    q.pop();

    int next = current;
    while (next != 0 && next <= 100000) {
      next = next * 2;

      if (next < 0 || next > 100000) continue;

      if (t[next] != -1) continue;

      q.push(next);
      t[next] = t[current];
    }

    for (int i = 0; i < 2; i++) {
      next = current + dx[i];

      if (next < 0 || next > 100000) continue;

      if (t[next] != -1) continue;

      q.push(next);
      t[next] = t[current] + 1;
    }
  }
}

int main() {
  cin >> N >> K;

  memset(t, -1, sizeof(t));

  bfs(N);

  cout << t[K];
}