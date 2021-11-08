#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

bool isPrime[10000];
int dist[10000];

void getPrimes() {
  isPrime[0] = false;
  isPrime[1] = false;

  for (int i = 2; i < 10000; i++) {
    if (isPrime[i]) {
      for (int j = i * 2; j < 10000; j += i) {
        isPrime[j] = false;
      }
    }
  }
}

void bfs(int start) {
  queue<int> q;

  q.push(start);
  dist[start] = 0;

  int current, next, cand;
  while (!q.empty()) {
    current = q.front();
    q.pop();

    next = current % 1000;
    for (int i = 1; i <= 9; i++) {
      cand = next + (1000 * i);
      if (isPrime[cand] && dist[cand] == -1) {
        q.push(cand);
        dist[cand] = dist[current] + 1;
      }
    }

    next = (current / 1000 * 1000) + (current % 100);
    for (int i = 0; i <= 9; i++) {
      cand = next + (100 * i);
      if (isPrime[cand] && dist[cand] == -1) {
        q.push(cand);
        dist[cand] = dist[current] + 1;
      }
    }

    next = (current / 100 * 100) + (current % 10);
    for (int i = 0; i <= 9; i++) {
      cand = next + (10 * i);
      if (isPrime[cand] && dist[cand] == -1) {
        q.push(cand);
        dist[cand] = dist[current] + 1;
      }
    }

    next = (current / 10 * 10);
    for (int i = 0; i <= 9; i++) {
      cand = next + i;
      if (isPrime[cand] && dist[cand] == -1) {
        q.push(cand);
        dist[cand] = dist[current] + 1;
      }
    }
  }
}

int main() {
  int T, A, B;

  cin >> T;

  memset(isPrime, true, sizeof(isPrime));
  getPrimes();

  while (T--) {
    cin >> A >> B;

    memset(dist, -1, sizeof(dist));
    bfs(A);

    cout << dist[B] << '\n';
  }
}