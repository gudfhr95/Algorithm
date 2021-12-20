#include <iostream>

#define rank _rank

using namespace std;

int parent[101];
int rank[101];

int Find(int x) {
  if (x == parent[x]) {
    return x;
  } else {
    return parent[x] = Find(parent[x]);
  }
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  if (x == y) return;

  if (rank[x] < rank[y]) swap(x, y);

  parent[y] = x;

  if (rank[x] == rank[y]) {
    rank[x] = rank[y] + 1;
  }
}

int main() {
  int n, m;

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;

    Union(a, b);
  }

  int result = 0;

  int p = Find(1);
  for (int i = 2; i <= n; i++) {
    if (Find(i) == p) {
      result++;
    }
  }

  cout << result;
}