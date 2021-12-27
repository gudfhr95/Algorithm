#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200000;

bool check[MAX + 1];
int dist[MAX + 1];
long long cnt[MAX + 1];

int main() {
  int n, m;

  cin >> n >> m;

  check[n] = true;
  dist[n] = 0;
  cnt[n] = 1;

  queue<int> q;
  q.push(n);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (int next : {now - 1, now + 1, now * 2}) {
      if (0 <= next && next <= MAX) {
        if (check[next] == false) {
          q.push(next);
          check[next] = true;
          dist[next] = dist[now] + 1;
          cnt[next] = cnt[now];
        } else if (dist[next] == dist[now] + 1) {
          cnt[next] += cnt[now];
        }
      }
    }
  }

  cout << dist[m] << '\n';
  cout << cnt[m] << '\n';

  return 0;
}