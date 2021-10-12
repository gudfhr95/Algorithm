#include <iostream>
#include <queue>

using namespace std;

int S;
int t[1001];

void bfs(int start) {
  queue<int> q;

  q.push(start);
  t[start] = 0;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    int next = current - 1;

    if (1 < next && next <= 1000) {
      if (t[next] == 0) {
        q.push(next);
        t[next] = t[current] + 1;
      } else if (t[next] > t[current] + 1) {
        q.push(next);
        t[next] = t[current] + 1;
      }
    }

    int mult = 1;
    while (true) {
      next = current + (current * mult);

      if (next > 1000) break;

      if (t[next] == 0) {
        q.push(next);
        t[next] = t[current] + 1 + mult;
      } else if (t[next] > t[current] + 1 + mult) {
        q.push(next);
        t[next] = t[current] + 1 + mult;
      }

      mult++;
    }
  }
}

int main() {
  cin >> S;

  bfs(1);

  cout << t[S];
}