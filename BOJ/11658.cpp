#include <iostream>

using namespace std;

int N, M;
int a[1025][1025];
int tree[1025][1025];

void update(int x, int y, int val) {
  for (int i = x; i <= N; i += (i & -i)) {
    for (int j = y; j <= N; j += (j & -j)) {
      tree[i][j] += val;
    }
  }
}

int sum(int x, int y) {
  int result = 0;
  for (int i = x; i > 0; i -= (i & -i)) {
    for (int j = y; j > 0; j -= (j & -j)) {
      result += tree[i][j];
    }
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a[i][j];
      update(i, j, a[i][j]);
    }
  }

  while (M--) {
    int what;

    cin >> what;

    if (what == 0) {
      int x, y, val;

      cin >> x >> y >> val;

      update(x, y, val - a[x][y]);
      a[x][y] = val;
    } else {
      int x1, y1, x2, y2;

      cin >> x1 >> y1 >> x2 >> y2;

      cout << sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) +
                  sum(x1 - 1, y1 - 1)
           << '\n';
    }
  }
}