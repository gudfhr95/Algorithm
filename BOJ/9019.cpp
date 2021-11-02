#include <cstring>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int from[10000];
char inst[10000];

void bfs(int start) {
  queue<int> q;

  q.push(start);
  from[start] = start;
  inst[start] = 0;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    int d = (current * 2) % 10000;
    if (from[d] == -1) {
      q.push(d);
      from[d] = current;
      inst[d] = 'D';
    }

    int s = ((current - 1) + 10000) % 10000;
    if (from[s] == -1) {
      q.push(s);
      from[s] = current;
      inst[s] = 'S';
    }

    int l = ((current * 10) % 10000) + (current / 1000);
    if (from[l] == -1) {
      q.push(l);
      from[l] = current;
      inst[l] = 'L';
    }

    int r = ((current % 10) * 1000) + (current / 10);
    if (from[r] == -1) {
      q.push(r);
      from[r] = current;
      inst[r] = 'R';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;

  cin >> T;

  while (T--) {
    int A, B;

    cin >> A >> B;

    memset(from, -1, sizeof(from));
    memset(inst, -1, sizeof(inst));
    bfs(A);

    stack<char> result;
    int next = B;
    while (true) {
      result.push(inst[next]);
      next = from[next];

      if (next == A) break;
    }

    while (!result.empty()) {
      cout << result.top();
      result.pop();
    }
    cout << '\n';
  }
}