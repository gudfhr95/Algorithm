#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int F, G, S, U, D;
int dist[1000001];

int main() {
  cin >> F >> S >> G >> U >> D;

  memset(dist, -1, sizeof(dist));

  queue<int> q;
  q.push(S);
  dist[S] = 0;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    int next = current + U;
    if (next <= F && dist[next] == -1) {
      q.push(next);
      dist[next] = dist[current] + 1;
    }

    next = current - D;
    if (next >= 1 && dist[next] == -1) {
      q.push(next);
      dist[next] = dist[current] + 1;
    }
  }

  if (dist[G] == -1) {
    cout << "use the stairs";
  } else {
    cout << dist[G];
  }
}