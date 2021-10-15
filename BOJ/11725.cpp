#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100111;

int N;
vector<int> tree[MAX];
int parent[MAX];
bool check[MAX];
int depth[MAX];
int dist[MAX];

void bfs(int start) {
  queue<int> q;

  q.push(start);
  depth[start] = 0;
  check[start] = true;
  parent[start] = 0;

  while (!q.empty()) {
    int current = q.front();

    q.pop();

    for (int next : tree[current]) {
      if (!check[next]) {
        depth[next] = depth[current] + 1;
        check[next] = true;
        parent[next] = current;
        q.push(next);
      }
    }
  }
}

int main() {
  scanf("%d", &N);

  for (int i = 0; i < N - 1; i++) {
    int u, v;

    scanf("%d %d", &u, &v);

    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  bfs(1);

  for (int i = 2; i <= N; i++) {
    printf("%d\n", parent[i]);
  }
}