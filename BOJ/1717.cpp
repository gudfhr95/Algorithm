#include <iostream>

using namespace std;

int parent[1000001];
int r[1000001];

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

  if (r[x] < r[y]) swap(x, y);

  parent[y] = x;

  if (r[x] == r[y]) {
    r[x] = r[y] + 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    parent[i] = i;
  }

  int op, a, b;
  for (int i = 0; i < m; i++) {
    cin >> op >> a >> b;

    if (op == 0) {
      Union(a, b);
    } else {
      if (Find(a) != Find(b)) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    }
  }
}