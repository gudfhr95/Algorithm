#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

int N;
vector<int> adj[100001];
bool visited[100001];

bool bfs(int start) {
  queue<int> q;

  q.push(start);
  visited[start] = true;

  while (!q.empty()) {
    int current = q.front();
    q.pop();

    set<int> next_set;
    for (int next : adj[current]) {
      if (visited[next]) continue;

      next_set.insert(next);
    }

    int size = next_set.size();
    int input;
    for (int i = 0; i < size; i++) {
      cin >> input;

      if (next_set.erase(input) == 0) return false;

      q.push(input);
      visited[input] = true;
    }
  }

  return true;
}

int main() {
  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int x, y;

    cin >> x >> y;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int start;
  cin >> start;

  if (start != 1) {
    cout << 0;
    return 0;
  }

  if (bfs(start)) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}